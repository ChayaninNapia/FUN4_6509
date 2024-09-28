#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from custom_interface.srv import ChangeMode, SetTaskspace, Mode3Control, ChangeModeDlc
from geometry_msgs.msg import PoseStamped,Twist
from sensor_msgs.msg import JointState
from math import pi
import roboticstoolbox as rtb
from spatialmath import SE3
import math
from std_srvs.srv import SetBool
from std_msgs.msg import Bool
from numpy.linalg import det
from numpy.linalg import eig
import numpy as np
from custom_msg.msg import Qtarget


class RobotServer(Node):
    def __init__(self):
        super().__init__('robot_server')
        self.srv = self.create_service(ChangeMode, 'change_mode', self.change_mode_callback)
        self.srv = self.create_service(ChangeModeDlc, 'mode2_dlc', self.mode2dlc_callback)

        self.target_sub = None  
        self.joint_pub = self.create_publisher(JointState, '/joint_states', 10)
        
        self.subscription = self.create_subscription(Twist,'/cmd_vel',self.setAngularVelocity_callback,10 )
        self.joint_sub = None
        
        self.set_task_server = self.create_service(SetTaskspace, 'move_to_taskspace', self.handle_move_to_taskspace)
        self.random_target_client = self.create_client(SetBool, 'activate_random')
        self.mode3_controller_client = self.create_client(Mode3Control, 'mode_3_controller')
        self.controller_timer = self.create_timer(0.01, self.sim_loop_move)
        self.mode2_controller_timer = self.create_timer(0.01, self.mode2_controller)
        self.sethome_server = self.create_service(SetBool, '/sethome_service', self.sethome)
        self.p = self.create_publisher(Qtarget, '/sethome',10)
        self.controller_timer.cancel()
        self.mode2_controller_timer.cancel()
        
        self.q_d = [0,0,0]
        self.q = [0, pi/4, pi/2]
        self.q_dot = [0,0,0]
        self.mode = 0
        self.velocity = 1.5
        self.dt = 0.01
        self.name = ["joint_1", "joint_2", "joint_3"]
        self.q_home = [0, pi/4, pi/2]
        self.current_q = [0, pi/4, pi/2,0]
        self.desire_V = [0,0,0]
        self.mode2_dlc = 1
        self.robot = rtb.DHRobot(
            [
                rtb.RevoluteMDH(d=0.2, alpha=0, offset=0),           # Joint 1
                rtb.RevoluteMDH(alpha=-pi/2, offset=-pi/2),          # Joint 2
                rtb.RevoluteMDH(a=0.25, d=-0.02, offset=pi/2),       # Joint 3
                rtb.RevoluteMDH(alpha=pi/2, d=0.28, offset=0)        # Joint 4 (End-Effector)
            ],
            name="robot"
        )

        self.joint_names = ["joint_1", "joint_2", "joint_3"]
        self.current_joint_state = [0.0, 0.0, 0.0]
        self.get_logger().info('Robot Server Node has been started.')
        self.active2 = True
        
        msg = JointState()
        msg.header.stamp = self.get_clock().now().to_msg()
        for i in range(len(self.q)):
            msg.position.append(self.q_home[i])
            msg.name.append(self.name[i])
        self.joint_pub.publish(msg)


    def q_dot_callback(self, msg: JointState):
        
        if self.mode != 2:
            return
        
        for i,q in enumerate(msg.position):
            self.current_q[i] = q
        
        if self.mode2_dlc == 1:
            self.J = self.robot.jacob0(self.current_q)
        else:
            self.J = self.robot.jacobe(self.current_q)
            
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
            self.active2 = False
            self.q_d = [0,0,0]
            self.q_dot = [0,0,0]
            self.mode = 0
            self.desire_V = [0,0,0]
            self.mode2_controller_timer.cancel()
            self.get_logger().warn(f"Manipulability is too low or NaN: {manipulability}. Approaching singularity!")
            self.get_logger().warn(f"please set home and set mode again")
        else:
            try:
                J_inv = np.linalg.inv(J_reduced)
                joint_velocities = J_inv @ desired_velocities
                print(f"Manipulability: {manipulability}")
                print(joint_velocities)
                
                self.q_dot = joint_velocities/10
            except np.linalg.LinAlgError as e:
                self.get_logger().warn(f"Failed to compute inverse of J_reduced due to near-singularity. Manipulability: {manipulability}")

    def setAngularVelocity_callback(self, msg:Twist):  
        self.desire_V = [msg.linear.x,msg.linear.y,msg.linear.z]

    def sethome(self, r, q):
        self.active2 = True
        msg = Qtarget()
        msg.current_q = list(map(float, self.q))
        msg.target_q = []
        self.p.publish(msg)
        self.active2 = True
        self.q_dot = [0,0,0]
        self.q = [0, pi/4, pi/2]

        return q

    def change_mode_callback(self, request, response):
        mode_name = ["Inverse Pose Kinematics", "Teleoperation", "Auto"]
        if request.mode in [1, 2, 3]:
            self.mode = request.mode
            self.get_logger().info(f'Changing mode to {self.mode} : {mode_name[request.mode - 1]}')
            
            self.stop_target_subscription()
            self.call_random_target_service(False)
            self.controller_timer.cancel()
            self.mode2_controller_timer.cancel()
            self.joint_sub = None

            if self.mode == 3:
                self.call_random_target_service(True)
                self.start_target_subscription()
                self.joint_sub = None
                
            elif self.mode == 2:
                self.controller_timer.cancel()
                self.stop_target_subscription()
                self.call_random_target_service(False)
                self.joint_sub = self.create_subscription(JointState, '/joint_states', self.q_dot_callback,10)
                self.mode2_controller_timer.reset()
                
                
            else:
                # If not mode 1, stop subscribing to /target topic
                self.call_random_target_service(False)
                self.stop_target_subscription()
                self.controller_timer.reset()
                self.mode2_controller_timer.cancel()
                self.joint_sub = None

            response.success = True
        else:
            self.get_logger().warn(f'Received invalid mode: {request.mode}')
            response.success = False
        return response
    
    def mode2dlc_callback(self, request, response):
        if request.mode in [1, 2]:
            if request.mode == 1:
                self.mode2_dlc = 1
            else:
                self.mode2_dlc = 2
            response.success = True
        else:
            self.get_logger().warn(f'Received invalid mode2_dlc: {request.mode}')
            response.success = False
            
        return response

    def start_target_subscription(self):
        
        if self.target_sub is None:
            self.target_sub = self.create_subscription(PoseStamped, '/target', self.target_callback, 10)
            self.get_logger().info('Subscribed to /target topic.')

    def stop_target_subscription(self):
       
        if self.target_sub is not None:
            self.destroy_subscription(self.target_sub)
            self.target_sub = None
            self.get_logger().info('Unsubscribed from /target topic.')
            
    def call_random_target_service(self, activate: bool):
        
        if not self.random_target_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().warn('Random target service not available.')
            return

        req = SetBool.Request()
        req.data = activate
        future = self.random_target_client.call_async(req)
        future.add_done_callback(self.handle_random_service_response)
        
    def handle_random_service_response(self, future):
        try:
            response = future.result()
            if response.success:
                self.get_logger().info(response.message)
            else:
                self.get_logger().warn(response.message)
        except Exception as e:
            self.get_logger().error(f'Failed to call random target service: {e}')
            
    def target_callback(self, msg: PoseStamped):
        
        if self.mode != 3:
            self.get_logger().warn("Please change to mode 3 !")
            return 
        
        x = msg.pose.position.x
        y = msg.pose.position.y
        z = msg.pose.position.z

        desired_pose = SE3(x, y, z)
        mask = [1, 1, 1, 0, 0, 0]  
        solution = self.robot.ikine_LM(desired_pose, mask=mask)

        if solution.success:      
            q_ik = solution.q[:3]
            # self.get_logger().info(f"IK Solution found: {q_ik}")

            joint_msg = JointState()
            joint_msg.header.stamp = self.get_clock().now().to_msg()
            joint_msg.name = self.joint_names
            joint_msg.position = q_ik.tolist()
            
            # self.q_d = list(joint_msg.position)
            # print(self.q_d)
            self.q_d = [float(joint) for joint in q_ik]
            self.stop_target_subscription()
            self.send_to_mode3_controller(self.q_d)
            
            # self.get_logger().info("Published joint states for joint_1, joint_2, joint_3.")
        else:
            self.get_logger().warn("Inverse Kinematics did not find a solution for the received target.")

    def send_to_mode3_controller(self, q_d):
        """Send the target joint positions to Mode3Controller."""
        if not self.mode3_controller_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().warn('Mode3Controller service not available.')
            return
        
        req = Mode3Control.Request()
        req.target_joint_positions = q_d  # Assuming this service accepts joint positions
        
        future = self.mode3_controller_client.call_async(req)
        future.add_done_callback(self.handle_mode3_response)
        
    def handle_mode3_response(self, future):
        try:
            response = future.result()
            if response.success:
                self.get_logger().info('Mode3Controller successfully moved to the target position.')
                self.start_target_subscription()  # Resubscribe to target
            else:
                self.get_logger().warn('Mode3Controller failed to move to the target position.')
        except Exception as e:
            self.get_logger().error(f'Failed to call Mode3Controller service: {e}')
        
    def sim_loop_move(self):
        msg = JointState()
        msg.header.stamp = self.get_clock().now().to_msg()

        for i in range(len(self.q)):
            error = self.q_d[i] - self.q[i]
            if abs(error) > 0.001:  
                direction = math.copysign(1, error)  
                delta = self.velocity * self.dt * direction 

                if abs(delta) > abs(error):
                    self.q[i] = self.q_d[i]
                else:
                    self.q[i] += delta

            msg.position.append(self.q[i])
            msg.name.append(self.name[i])
        
        self.joint_pub.publish(msg)
        
    def mode2_controller(self):
        print(f'mode2timer active2: {self.active2}')
        if self.active2:       
            self.home_state = False
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
            
        
    def handle_move_to_taskspace(self, request, response):
        
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

            response.success = True
            self.get_logger().info("Robot successfully moved to the target task space coordinates.")
        else:
            response.success = False
            self.get_logger().warn("Failed to find an IK solution. Robot did not move.")

        return response
        
def main(args=None):
    rclpy.init(args=args)
    node = RobotServer()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
