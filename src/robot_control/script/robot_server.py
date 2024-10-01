#!/usr/bin/env python3

# this node compute ikine then send goal to action server 
import rclpy
from rclpy.node import Node
from robot_action.srv import GenTarget, ChangeMode, SetTaskspace
import roboticstoolbox as rtb
from spatialmath import SE3
import math
from sensor_msgs.msg import JointState
from geometry_msgs.msg import PoseStamped
from math import pi
from rclpy.action import ActionClient
from robot_action.action import PoseGoal
from rclpy.action.client import ClientGoalHandle, GoalStatus
from geometry_msgs.msg import Twist
import numpy as np
from numpy.linalg import det
from std_srvs.srv import SetBool

class RobotServerNode(Node):
    def __init__(self):
        super().__init__('robot_server_node')
        self.get_logger().info('robot server has been started')
        
        self.joint_pub = self.create_publisher(JointState, '/joint_states', 10)
        self.joint_current_pub = self.create_publisher(JointState, '/current_joint_states', 10)
        self.subscription = None
        self.srv = self.create_service(ChangeMode, 'change_mode', self.change_mode_callback)
        self.sethome_service = self.create_service(SetBool, 'sethome', self.sethome_callback)
        self.set_task_server = self.create_service(SetTaskspace, 'set_taskspace', self.mode1_set_taskspace)
        self.random_client = self.create_client(GenTarget, 'random_task',)
        self.robot_client = ActionClient(self, PoseGoal, 'pose_goal')
        
        self.robot_client = ActionClient(self, PoseGoal, 'pose_goal')
        self.goal_handle = None  
        self.mode = 0
        self.q_d = [0.0 ,0.785 , 1.57]
        self.desire_V = [0.0, 0.0, 0.0]
        self.q = [0.0 ,0.785 , 1.57]
        self.dt = 0.01
        self.name = ["joint_1", "joint_2", "joint_3"]
        
        self.mode2_timer = self.create_timer(0.01, self.mode2_controller)
        self.mode3_timer = self.create_timer(1.0, self.mode3)
    
        self.mode2_timer.cancel()
        self.mode3_timer.cancel()
        
        self.working = False
        
        self.robot = rtb.DHRobot(
            [
                rtb.RevoluteMDH(d=0.2, alpha=0, offset=0),           # Joint 1
                rtb.RevoluteMDH(alpha=-pi/2, offset=-pi/2),          # Joint 2
                rtb.RevoluteMDH(a=0.25, d=-0.02, offset=pi/2),       # Joint 3
                rtb.RevoluteMDH(alpha=pi/2, d=0.28, offset=0)        # Joint 4 (End-Effector)
            ],
            name="robot"
        )
        
        self.waiting_for_result = False
        self.sendgoal(0, [0.0 ,0.785 , 1.57])
    
    def sethome_callback(self, req, res:SetBool.Response):
        self.send_current_q()
        self.sendgoal(0, [0.0 ,0.785 , 1.57])
        self.mode = 0
        
        res.success = True
        return res
    
    def send_current_q(self):
        
        msg = JointState()
        msg.header.stamp = self.get_clock().now().to_msg()
        
        for i in range(len(self.q)):
            msg.position.append(self.q[i])
            msg.name.append(self.name[i])
            
        self.joint_current_pub.publish(msg)
        
    def compute_ikine(self,msg:PoseStamped):
        x = msg.pose.position.x
        y = msg.pose.position.y
        z = msg.pose.position.z

        desired_pose = SE3(x, y, z)
        mask = [1, 1, 1, 0, 0, 0]  
        solution = self.robot.ikine_LM(desired_pose, mask=mask)

        if solution.success:      
            q_ik = solution.q[:3]  
            self.get_logger().info(f'Desire q : {str(self.q_d)}') 
        else:
            self.get_logger().warn("Inverse Kinematics did not find a solution for the received target.")
            
        return [float(joint) for joint in q_ik]
        
        
    def call_random_to_ikine(self):
        
        while not self.random_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Waiting for service...')
            
        request = GenTarget.Request()
        request.trigger = True 
       
        self.future = self.random_client.call_async(request)
        self.future.add_done_callback(self.handle_response)
        
        
    def handle_response(self, future):
        try:
            response = future.result()
            taskspace_pose = response.taskspace
            self.get_logger().info(f'''Position: x={taskspace_pose.pose.position.x},y={taskspace_pose.pose.position.y}, z={taskspace_pose.pose.position.z}''')
            
            
            self.q_d = self.compute_ikine(response.taskspace)
            
        except Exception as e:
            self.get_logger().error(f'Service call failed: {e}')
            
    '''  --- action client section --- '''        
            
    def sendgoal(self, task_type, task):
        self.robot_client.wait_for_server()
        goal = PoseGoal.Goal()
        goal.task_type = task_type
        goal.task = task
        self.get_logger().info("sending_goal...")
        self.robot_client.send_goal_async(goal, feedback_callback=self.feedback_callback).add_done_callback(self.goal_response_callback)
        
        self.waiting_for_result = True
        
    
    def feedback_callback(self, feedback_msg:PoseGoal):
        current_q = feedback_msg.feedback.current_q.tolist()
        self.q = current_q
        # self.get_logger().info(f'current q {type(current_q)} : {str(current_q)}')
        
    def goal_response_callback(self, future):
        
        self.goal_handle : ClientGoalHandle = future.result()
        
        if self.goal_handle.accepted:
            self.working = True
            self.get_logger().info("goal got accepted")
            self.goal_handle.get_result_async().add_done_callback(self.goal_result_callback)
            
            
    def goal_result_callback(self, future):
        
        self.working = False
        status = future.result().status
        
        if status == GoalStatus.STATUS_CANCELED:
            self.get_logger().warn("Canceled")
        
        self.waiting_for_result = False
        result = future.result().result
        self.get_logger().info(f'return {str(result)}')
        
    ''' ---------------------------- '''   
    
    def change_mode_callback(self, request, response):
        
        if self.working:
                    self.goal_handle.cancel_goal_async()
                    
                    
        mode_name_map = {
        1: "Inverse Pose Kinematics",
        20: "Teleoperation base reference",
        21: "Teleoperation end_effector reference",
        3: "Auto"
    }
        self.send_current_q()
        self.mode = request.mode
        self.mode3_timer.cancel()
        self.mode2_timer.cancel()
        self.destroy_subscription(self.subscription)
        self.subscription = None
      
        if request.mode in [1, 20, 21, 3]:
            
            if self.mode == 3:
                self.mode3_timer.reset()
            elif self.mode == 20 or self.mode == 21:
                self.subscription = self.create_subscription(Twist,'/cmd_vel',self.mode2_callback,10 )
                self.mode2_timer.reset()

                

            
            self.get_logger().info(f'Changing mode to {self.mode} : {mode_name_map[request.mode]}')
            response.success = True
        else:
            self.get_logger().warn(f'Received invalid mode: {request.mode}')
            response.success = False
        return response
                
    def mode1_set_taskspace(self, request:SetTaskspace.Request, response):
        
        if self.mode != 1:
            self.get_logger().warn("Please change to mode 1 before using this service!")
            response.success = False
            return response
        
        self.get_logger().info(f"Received target taskspace coordinates: x={request.x}, y={request.y}, z={request.z}")
        x = request.x
        y = request.y
        z = request.z

        desired_pose = SE3(x, y, z)
        mask = [1, 1, 1, 0, 0, 0]  
 
        solution = self.robot.ikine_LM(desired_pose, mask=mask)

        if solution.success:
            q_ik = solution.q[:3]
            self.get_logger().info(f"IK Solution found: {solution.q[:3]}")
            self.q_d = q_ik.tolist()
            self.sendgoal(0, self.q_d)
            
            
            response.success = True
            self.get_logger().info("Robot successfully moved to the target task space coordinates.")
        else:
            response.success = False
            self.get_logger().warn("Failed to find an IK solution. Robot did not move.")

        return response
    
    def mode2_callback(self, msg):
        self.desire_V = [msg.linear.x,msg.linear.y,msg.linear.z]
        
    def mode2_controller(self):
        
        self.q_arr = np.array(self.q)
        self.q_arr = np.append(self.q_arr, 0.0)
        
        if self.mode == 20:
            self.J = self.robot.jacob0(self.q_arr)
        else:
            self.J = self.robot.jacobe(self.q_arr)
            
        J_reduced = self.J[0:3, 0:-1]
        desired_velocities = self.desire_V
        
        determinant = det(J_reduced @ J_reduced.T)
    
        if determinant < 0:
            self.get_logger().warn(f"Negative determinant encountered: {determinant}. Cannot compute manipulability.")
            manipulability = np.nan
        else:
            manipulability = np.sqrt(determinant)
        
        A = J_reduced @ J_reduced.T

        if np.isnan(manipulability) or manipulability < 1e-3:
            self.get_logger().warn(f"Manipulability is too low or NaN: {manipulability}. Approaching singularity!")
            self.get_logger().warn(f"please /sethome and /change_mode again")
            self.desire_V = [0.0, 0.0, 0.0]
            self.mode2_timer.cancel()
        else:
            try:
                J_inv = np.linalg.inv(J_reduced)
                joint_velocities = J_inv @ desired_velocities
                print(f"Manipulability: {manipulability}")
                print(joint_velocities)
                self.q_dot = joint_velocities/10
                
            except np.linalg.LinAlgError as e:
                self.get_logger().warn(f"Failed to compute inverse of J_reduced due to near-singularity. Manipulability: {manipulability}")

        msg = JointState()
        msg.header.stamp = self.get_clock().now().to_msg()
        q_d = self.q_dot[0:3]
        self.q[0] = self.q[0] + (q_d[0] * self.dt)
        self.q[1] = self.q[1] + (q_d[1] * self.dt)
        self.q[2] = self.q[2] + (q_d[2] * self.dt)
        for i in range(len(self.q)):
            msg.position.append(self.q[i])
            msg.name.append(self.name[i])
        self.joint_pub.publish(msg)
        
                
                
    def mode3(self):
        if self.mode == 3:
            if not self.waiting_for_result:  
                self.call_random_to_ikine()
                self.sendgoal(0, self.q_d)
            else:
                self.get_logger().info("Waiting for action result...")
    
        
     

def main(args=None):
    rclpy.init(args=args)
    node = RobotServerNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
