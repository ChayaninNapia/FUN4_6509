#!/usr/bin/env python3

import time
import rclpy
from rclpy.node import Node
from robot_action.action import PoseGoal
from rclpy.action.server import ServerGoalHandle ,GoalResponse, CancelResponse
from rclpy.action import ActionServer
from sensor_msgs.msg import JointState
from math import pi
import math
from rclpy.executors import MultiThreadedExecutor
from rclpy.callback_groups import ReentrantCallbackGroup


class RobotActionServer(Node):

    def __init__(self):
        super().__init__('robot_action_server_node')
        self.get_logger().info('Action server has been started!')
        self.joint_pub = self.create_publisher(JointState, '/joint_states', 10)
        self.current_q_sub = self.create_subscription(JointState, '/current_joint_states', self.set_current_q, 10)
        self.action_server = ActionServer(
            self,
            PoseGoal,
            'pose_goal',
            goal_callback=self.goal_callback,
            cancel_callback=self.cancel_callback,
            execute_callback=self.execute_callback,
            callback_group=ReentrantCallbackGroup()
        )
        
        self.q_d = [0.0, 0.0, 0.0]
        self.q = [0.0, pi/4, pi/2] 
        self.velocity = 1.5
        self.dt = 0.01
        self.name = ["joint_1", "joint_2", "joint_3"]
        self.q_home = [0, pi/4, pi/2]
        
        self.kp = [2.0,2.5,2.5]
        
       
    def set_current_q(self, msg:JointState):
        
        for i in range(3):
            self.q[i] = msg.position[i]


    def goal_callback(self, goal_request:PoseGoal.Goal):
        modename = ["configuration space", "task space"]
        mode = goal_request.task_type
        target = goal_request.task
        self.q_d = target.tolist()
        if mode not in [0,1]:
            self.get_logger().warn(f'invalid mode type {target}, try again.')
            return GoalResponse.REJECT
        
        self.get_logger().info(f'accept goal |  mode {mode}: {modename[mode]} | target: {str(target)}')
        
        return GoalResponse.ACCEPT
    
    def cancel_callback(self, goal_handle : ServerGoalHandle):
        self.get_logger().info("current goal cancelled")
        return CancelResponse.ACCEPT

    
    def execute_callback(self, goal_handle:ServerGoalHandle):
          
        result = PoseGoal.Result()
        feedback = PoseGoal.Feedback()
        while True:    
                       
            feedback.current_q = list(map(float, self.q))
            goal_handle.publish_feedback(feedback)
            if goal_handle.is_cancel_requested:
                self.get_logger().warn("Canceling the goal")
                goal_handle.canceled()
                result.success = False
                return result
            msg = JointState()
            msg.header.stamp = self.get_clock().now().to_msg()
            all_joints_reached = True
            for i in range(len(self.q)):
                error = self.q_d[i] - self.q[i]
                if abs(error) > 0.001:  
                    direction = math.copysign(1, error)  
                    delta = self.kp[i] * self.dt * direction 

                    if abs(delta) > abs(error):
                        self.q[i] = self.q_d[i]
                    else:
                        self.q[i] += delta
                        
                    all_joints_reached = False

                msg.position.append(self.q[i])
                msg.name.append(self.name[i])   
                   
            self.joint_pub.publish(msg)    
            
            if all_joints_reached:
                break
            time.sleep(0.01)
            
        goal_handle.succeed()
        result.success = True
        self.get_logger().info("return result")
        return result

def main(args=None):
    rclpy.init(args=args)
    node = RobotActionServer()
    rclpy.spin(node, MultiThreadedExecutor())
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
