#!/usr/bin/python3

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import JointState
from math import pi
from spatialmath import *
import numpy as np
from std_msgs.msg import Bool

class WorkspaceNode(Node):
    def __init__(self):
        super().__init__('workspace_move_node')
        self.joint_pub = self.create_publisher(JointState, "/joint_states", 10)
        self.flag_publisher = self.create_publisher(Bool, 'stop_plot', 10)
        self.dt = 0.01
        self.freq = 0.01
        self.timer = self.create_timer(self.freq, self.sim_loop)
        self.q = [0.0, 0.0, 0.0]
        self.cmd_vel = [0.0, 0.0, 0.0]
        self.name = ["joint_1", "joint_2", "joint_3"]
        self.state = True

    def sim_loop(self):
        msg = JointState()
        msg.header.stamp = self.get_clock().now().to_msg()
        q_d = [8.0, 5.0, 3.0]
        self.q[0] = self.q[0] + (q_d[0] * self.dt)
        
        
        if self.q[0] > 2*pi:
            self.q[1] = self.q[1] + (q_d[1] * self.dt)
            self.q[0] = 0
        
        if self.q[1] > pi:
            self.state = False
            flag_msg = Bool()
            flag_msg.data = False
            self.flag_publisher.publish(flag_msg)
            self.timer.cancel()
        
        for i in range(len(self.q)):
            msg.position.append(self.q[i])
            msg.name.append(self.name[i])
        if self.state:
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
