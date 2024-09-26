#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
import math
from math import atan2
from sensor_msgs.msg import JointState

class PositionTranformerNode(Node):
    def __init__(self):
        super().__init__('position_tranformer_node')  
        
        self.get_logger().info('Node has been started.')
        
       
        self.q_d = [0.0, 1.57, 1.57]
        self.joint_pub = self.create_publisher(JointState, "/joint_states", 10)
        self.joint_sub = self.create_subscription(JointState, "/joint_states", self.joint_state_callback, 10)
        self.dt = 0.01
        self.create_timer(self.dt, self.sim_loop)
        self.initial_q = [0.0, 0.0, 0.0]
        self.q = self.initial_q
        self.current_q = self.initial_q
        
        self.name = ["joint_1", "joint_2", "joint_3"]
        self.velocity = 0.35
        
        
        self.Kp = 0.01
        
        for i in range(len(self.q)):
            msg = JointState()
            msg.header.stamp = self.get_clock().now().to_msg()
            msg.position.append(self.q[i])
            msg.name.append(self.name[i])
        self.joint_pub.publish(msg)

    def sim_loop(self):
        msg = JointState()
        msg.header.stamp = self.get_clock().now().to_msg()
        
        # Instead of calculating the error and updating `self.q`, we directly set `self.q` to the desired values.
        self.q = self.q_d
        
        # Publish the joint states directly from `self.q`
        for i in range(len(self.q)):
            msg.position.append(self.q[i])
            msg.name.append(self.name[i])
            
        self.joint_pub.publish(msg)
        
    def sim_loop_move(self):
        msg = JointState()
        msg.header.stamp = self.get_clock().now().to_msg()

        # Move joints toward the desired positions (self.q_d) at a constant velocity
        for i in range(len(self.q)):
            error = self.q_d[i] - self.q[i]
            if abs(error) > 0.001:  # Small tolerance to stop motion when close enough
                direction = math.copysign(1, error)  # Get the direction of motion
                delta = self.velocity * self.dt * direction  # Change per timestep

                # Ensure we don't overshoot the target
                if abs(delta) > abs(error):
                    self.q[i] = self.q_d[i]
                else:
                    self.q[i] += delta

            msg.position.append(self.q[i])
            msg.name.append(self.name[i])
        
        # Publish the joint states with updated positions
        self.joint_pub.publish(msg)

    def joint_state_callback(self, msg):
        if len(msg.position) >= 3:
            self.current_q = list(msg.position[:3])  # Get the first three joint positions
            # self.get_logger().info(f"Current joint positions: {self.current_q}")

    def manual_ikine(self):
        
        l1 = 0.2   # 200 / 1000
        l2 = 0.06  # 60 / 1000
        l3 = 0.25  # 250 / 1000
        l4 = 0.1   # 100 / 1000
        l5 = 0.28  # 280 / 1000

        self.target = [0.28, -0.02, 0.23]
        z_offset = self.target[2] - l1
        
        r_xz = math.hypot(self.target[0], z_offset)
        r_xy = math.hypot(self.target[0], self.target[1])
        
        rr = math.hypot(self.target[0], self.target[1], z_offset)
        c3 = ((r_xz**2 - l3**2 - l5**2) / (2*l3*l5))
        s3 = math.sqrt(1-c3**2)
    
        
        q2 = math.pi/2 - atan2(z_offset, self.target[0]) - atan2(l1*s3, l3+l5*c3) 
        q3 = atan2(s3, c3)
        R = l3 * math.sin(q2) + l5*math.sin(q3)
        q1 = atan2(self.target[1], self.target[0]) + atan2(0.02, R)
        # angle_degrees = math.degrees(q1)
        # print(f"Angle in degrees: {angle_degrees}")
        # print(f'target: {self.target}')
        # print(q1,q2,q3)
    
        self.q_d = [0.09788605, -0.00770906,  0.00770906]
        # self.q_d = [q1, q2, q3]

def main(args=None):
    rclpy.init(args=args)
    node = PositionTranformerNode()
    node.manual_ikine()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
