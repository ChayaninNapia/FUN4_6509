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

class RandomTargetPublisher(Node):
    def __init__(self):
        super().__init__('random_target_publisher')
        
        self.target_pub = self.create_publisher(PoseStamped, '/target', 10)
        self.timer = self.create_timer(5.0, self.publish_random_target)
        self.timer.cancel()
        self.srv = self.create_service(SetBool, 'activate_random', self.activate_random_target_callback)

        self.active = False  # Flag to track if random publishing is active
        self.get_logger().info('Random Target Publisher has been started.')

        self.l1 = 0.2   # 200 / 1000
        self.l2 = 0.06  # 60 / 1000
        self.l3 = 0.25  # 250 / 1000
        self.l4 = 0.1   # 100 / 1000
        self.l5 = 0.28  # 280 / 1000
    
    def activate_random_target_callback(self, request:SetBool.Request, response:SetBool.Response):
        
        if request.data:
            if not self.active:
                self.timer.reset()  # Start or restart the timer
                self.active = True
                response.success = True
                response.message = 'Random target publishing started.'
                self.get_logger().info(response.message)
            else:
                response.success = False
                response.message = 'Random target publishing is already active.'
                self.get_logger().warn(response.message)
        else:  
            if self.active:
                self.timer.cancel()  # Stop the timer
                self.active = False
                response.success = True
                response.message = 'Random target publishing stopped.'
                self.get_logger().info(response.message)
            else:
                response.success = False
                response.message = 'Random target publishing is already inactive.'
                self.get_logger().warn(response.message)
                
        return response
        
    def publish_random_target(self):
        
        l1 = 0.2   # 200 / 1000
        l2 = 0.06  # 60 / 1000
        l3 = 0.25  # 250 / 1000
        l4 = 0.1   # 100 / 1000
        l5 = 0.28  # 280 / 1000
        
        msg = PoseStamped()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.header.frame_id = "link_0"


        # self.get_logger().info(f'Publishing random target: Position x={msg.pose.position.x}, y={msg.pose.position.y}, z={msg.pose.position.z}')
        while True:
            msg.pose.position.x = random.uniform(-(self.l3+self.l5), self.l3+self.l5)  
            msg.pose.position.y = random.uniform(-(self.l3+self.l5), self.l3+self.l5)  
            msg.pose.position.z = random.uniform(self.l1 - self.l3 - self.l5, self.l1 + self.l3 +self.l5)
            if self.check_valid(msg):
                break 
            
            
        print("pos valid UwU")
        self.target_pub.publish(msg)
        
        
        return
    

        
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

        mask = [1, 1, 1, 0, 0, 0]  # Only consider translation
        
        desired_pose = SE3(pos.pose.position.x, pos.pose.position.y, pos.pose.position.z)
        solution = robot.ikine_LM(desired_pose, mask=mask)

        if solution.success:
            return True    
        else:
            return False
        
def main(args=None):
    rclpy.init(args=args)
    node = RandomTargetPublisher()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
