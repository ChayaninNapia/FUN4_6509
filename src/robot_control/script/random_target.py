#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseStamped
import random
import roboticstoolbox as rtb
from math import pi
import numpy as np
from spatialmath import SE3
from std_srvs.srv import SetBool
from robot_action.srv import GenTarget
from tf2_ros import Buffer, TransformListener
from geometry_msgs.msg import TransformStamped
import tf_transformations

class RandomTargetPublisher(Node):
    def __init__(self):
        super().__init__('random_target_publisher')
        
        self.tf_buffer = Buffer()
        self.tf_listener = TransformListener(self.tf_buffer, self)
        self.srv = self.create_service(GenTarget, 'random_task', self.random_target_callback)
        self.get_logger().info('Random Target Publisher has been started.')
        self.pub_timer = self.create_timer(1.0, self.pub)

        self.pub_timer.cancel()
        

        self.l1 = 0.2   # 200 / 1000
        self.l2 = 0.06  # 60 / 1000
        self.l3 = 0.25  # 250 / 1000
        self.l4 = 0.1   # 100 / 1000
        self.l5 = 0.28  # 280 / 1000
        
        self.declare_parameter('mode', 0)
        self.mode = self.get_parameter('mode').get_parameter_value().integer_value
        
        # Conditional publisher creation based on mode
        if self.mode == 1:
            self.publisher_ = self.create_publisher(PoseStamped, '/target', 10)
            self.publisher_end = self.create_publisher(PoseStamped, '/end_effector', 10)
            self.pub_timer.reset()
            self.get_logger().info('Publisher for /target has been created.')
            
        elif self.mode == 2:
            self.get_logger().info('No publisher created as mode is not 1.')
            
        else:
            self.get_logger().warn('WTF?')
            
    def pub(self):
        msg = self.generate()
        self.publisher_.publish(msg)
        self.get_transform()
    
    def random_target_callback(self, request:GenTarget.Request, response:GenTarget.Response):

        l1 = 0.2   # 200 / 1000
        l2 = 0.06  # 60 / 1000
        l3 = 0.25  # 250 / 1000
        l4 = 0.1   # 100 / 1000
        l5 = 0.28  # 280 / 1000
        
        msg = PoseStamped()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.header.frame_id = "link_0"

        while True:
            msg.pose.position.x = random.uniform(-(self.l3+self.l5), self.l3+self.l5)  
            msg.pose.position.y = random.uniform(-(self.l3+self.l5), self.l3+self.l5)  
            msg.pose.position.z = random.uniform(self.l1 - self.l3 - self.l5, self.l1 + self.l3 +self.l5)
            if self.check_valid(msg):
                break 
            
            
        print("pos valid UwU")
        
        response.taskspace = msg
        
        return response
        
        
    def check_valid(self,pos:PoseStamped):
        
        
        robot = rtb.DHRobot(
            [
                rtb.RevoluteMDH(d=self.l1, alpha=0, offset=0), 
                rtb.RevoluteMDH(alpha=-pi/2, offset=-pi/2),  
                rtb.RevoluteMDH(a=self.l3, d=-0.02, offset=pi/2), 
                rtb.RevoluteMDH(alpha=pi/2, d=self.l5, offset=0) 
            ],
        name="robot"    
        )

        mask = [1, 1, 1, 0, 0, 0] 
        
        desired_pose = SE3(pos.pose.position.x, pos.pose.position.y, pos.pose.position.z)
        solution = robot.ikine_LM(desired_pose, mask=mask)

        if solution.success:
            return True    
        else:
            return False
        
    def generate(self):
        l1 = 0.2   # 200 / 1000
        l2 = 0.06  # 60 / 1000
        l3 = 0.25  # 250 / 1000
        l4 = 0.1   # 100 / 1000
        l5 = 0.28  # 280 / 1000
        
        msg = PoseStamped()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.header.frame_id = "link_0"

        while True:
            msg.pose.position.x = random.uniform(-(self.l3+self.l5), self.l3+self.l5)  
            msg.pose.position.y = random.uniform(-(self.l3+self.l5), self.l3+self.l5)  
            msg.pose.position.z = random.uniform(self.l1 - self.l3 - self.l5, self.l1 + self.l3 +self.l5)
            if self.check_valid(msg):
                break 
            
            
        print("pos valid UwU")
        return msg
    
    def get_transform(self):
        try:
            transform = self.tf_buffer.lookup_transform('link_0', 'end_effector', rclpy.time.Time())
            self.print_transform_matrix(transform)

        except Exception as e:
            self.get_logger().warn(f"Could not transform: {str(e)}")
    
    def print_transform_matrix(self, transform: TransformStamped):
        translation = transform.transform.translation
        rotation = transform.transform.rotation

        quaternion = [rotation.x, rotation.y, rotation.z, rotation.w]
        rotation_matrix = tf_transformations.quaternion_matrix(quaternion)

        rotation_matrix[0, 3] = translation.x
        rotation_matrix[1, 3] = translation.y
        rotation_matrix[2, 3] = translation.z

        msg = PoseStamped()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.header.frame_id = "link_0"
        msg.pose.position.x = translation.x
        msg.pose.position.y = translation.y
        msg.pose.position.z = translation.z
        
        msg.pose.orientation.x = rotation.x
        msg.pose.orientation.y = rotation.y
        msg.pose.orientation.z = rotation.z
        msg.pose.orientation.w = rotation.w

        self.get_logger().info("Transformation Matrix:")
        self.get_logger().info(f"\n{rotation_matrix}")
        
        self.publisher_end.publish(msg)
    
def main(args=None):
    rclpy.init(args=args)
    node = RandomTargetPublisher()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
