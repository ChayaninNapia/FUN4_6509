#!/usr/bin/python3

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import JointState
from math import pi
from spatialmath import *
import numpy as np

class WorkspaceNode(Node):
    def __init__(self):
        super().__init__('workspace_move_node')
        self.joint_pub = self.create_publisher(JointState, "/joint_states", 10)
        self.dt = 0.01
        self.freq = 0.01
        self.create_timer(self.freq, self.sim_loop)
        self.q = [0.0, 0.0, 0.0]
        self.cmd_vel = [0.0, 0.0, 0.0]
        self.name = ["joint_1", "joint_2", "joint_3"]

    def sim_loop(self):
        msg = JointState()
        msg.header.stamp = self.get_clock().now().to_msg()
        q_d = [4.0, 5.0, 3.0]
        self.q[0] = self.q[0] + (q_d[0] * self.dt)
        
        if self.q[0] > 2*pi:
            self.q[1] = self.q[1] + (q_d[1] * self.dt)
            self.q[0] = 0
        
        
        for i in range(len(self.q)):
            msg.position.append(self.q[i])
            msg.name.append(self.name[i])
        self.joint_pub.publish(msg)
        print(self.q)
        
def main(args=None):
    rclpy.init(args=args)
    node = WorkspaceNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__=='__main__':
    main()
