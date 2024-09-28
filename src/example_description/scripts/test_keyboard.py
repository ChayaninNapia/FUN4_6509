#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
import roboticstoolbox as rtb
import numpy as np
from math import pi
from numpy.linalg import det
from numpy.linalg import eig
from sensor_msgs.msg import JointState
from std_srvs.srv import SetBool
import math

class TeleopListener(Node):
    def __init__(self):
        super().__init__('teleop_listener')

        # Subscribe to the /cmd_vel topic which publishes Twist messages
        self.subscription = self.create_subscription(Twist,'/cmd_vel',self.setAngularVelocity_callback,10 )
        self.joint_sub = self.create_subscription(JointState, '/joint_states', self.q_dot_callback,10)
        self.joint_pub = self.create_publisher(JointState, '/joint_states',10)
        self.timer = self.create_timer(0.01, self.control_loop_callback)

        self.get_logger().info('Teleop Listener Node has been started, subscribing to /cmd_vel.')
        
        self.set_home_server = self.create_service(SetBool, '',self.set_home_callback)
    
        self.robot = rtb.DHRobot(
            [
                rtb.RevoluteMDH(d=0.2, alpha=0, offset=0),           # Joint 1
                rtb.RevoluteMDH(alpha=-pi/2, offset=-pi/2),          # Joint 2
                rtb.RevoluteMDH(a=0.25, d=-0.02, offset=pi/2),       # Joint 3
                rtb.RevoluteMDH(alpha=pi/2, d=0.28, offset=0)        # Joint 4 (End-Effector)
            ],
            name="robot"
        )

        np.set_printoptions(precision=6, suppress=True)

        self.current_q = self.q = [0, pi/4, pi/2,0]
        self.q_home = [0, pi/4, pi/2]
        self.q = self.current_q[0:3]
        self.desire_V = [0,0,0]
        self.q_dot = [0,0,0]     
        self.dt = 0.01  
        self.name = ["joint_1", "joint_2", "joint_3"]
        self.home_state = True
        self.velocity = 0.5
        
    def setAngularVelocity_callback(self, msg:Twist):  
        self.get_logger().info(f'Received /cmd_vel: linear=({msg.linear.x}, {msg.linear.y}, {msg.linear.z}), '
                               f'angular=({msg.angular.x}, {msg.angular.y}, {msg.angular.z})')
        
        self.desire_V = [msg.linear.x,msg.linear.y,msg.linear.z]
        
    def q_dot_callback(self, msg: JointState):
        
        for i,q in enumerate(msg.position):
            self.current_q[i] = q
        
        self.J = self.robot.jacob0(self.current_q)
        J_reduced = self.J[0:3, 0:-1]
        desired_velocities = self.desire_V
        
        determinant = det(J_reduced @ J_reduced.T)
    
        if determinant < 0:
            self.get_logger().warn(f"Negative determinant encountered: {determinant}. Cannot compute manipulability.")
            manipulability = np.nan
        else:
            manipulability = np.sqrt(determinant)
        
        A = J_reduced @ J_reduced.T
        eigenvalues, eigenvectors = eig(A)
        
    
        A = J_reduced @ J_reduced.T

        if np.isnan(manipulability) or manipulability < 1e-3:
            self.timer.cancel()
            self.get_logger().warn(f"Manipulability is too low or NaN: {manipulability}. Approaching singularity!")
        else:
            try:
                J_inv = np.linalg.inv(J_reduced)
                joint_velocities = J_inv @ desired_velocities
                print(f"Manipulability: {manipulability}")
                print(joint_velocities)
                
                self.q_dot = joint_velocities/10
            except np.linalg.LinAlgError as e:
                self.get_logger().warn(f"Failed to compute inverse of J_reduced due to near-singularity. Manipulability: {manipulability}")
                
    def control_loop_callback(self):
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
        
            
            

def main(args=None):
    rclpy.init(args=args)
    node = TeleopListener()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
