#!/usr/bin/python3

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import JointState
from custom_interface.srv import Mode3Control  
import math
from std_msgs.msg import Bool
from math import pi
from custom_msg.msg import Qtarget
from std_msgs.msg import Int16

class Mode3Controller(Node):
    def __init__(self):
        super().__init__('mode_3_controller_node')
        self.joint_pub = self.create_publisher(JointState, '/joint_states', 10)
        self.m3 = self.create_publisher(Int16, '/mode3finish', 10)
        self.controller_service = self.create_service(Mode3Control, 'mode_3_controller', self.handle_mode3_control_request)
        self.controller_timer = None  
        self.sethome_sub = self.create_subscription(Qtarget, '/sethome', self.sethome,10)
        self.q_d = []
        self.q = [0.0, 0.0, 0.0]  
        self.velocity = 2.5
        self.dt = 0.01
        self.joint_names = ["joint_1", "joint_2", "joint_3"]
        self.q_home = [0, pi/4, pi/2]

    def handle_mode3_control_request(self, request, response):

        self.q_d = request.target_joint_positions
        self.get_logger().info(f'Received new target joint positions: {self.q_d}')

        if self.controller_timer is None:
            self.controller_timer = self.create_timer(0.01, self.sim_loop_move)
        
        response.success = True
        return response

    def sethome(self, msg:Qtarget):
        self.q = msg.current_q
        self.controller_timer = self.create_timer(0.01, self.sim_loop_move)
        self.q_d = self.q_home

    def sim_loop_move(self):
        msg = JointState()
        msg.header.stamp = self.get_clock().now().to_msg()

        all_joints_reached = True

        for i in range(len(self.q)):
            error = self.q_d[i] - self.q[i]
            if abs(error) > 0.001:  
                direction = math.copysign(1, error)  
                delta = self.velocity * self.dt * direction 

                if abs(delta) > abs(error):
                    self.q[i] = self.q_d[i]
                else:
                    self.q[i] += delta

                all_joints_reached = False  

            msg.position.append(self.q[i])
            msg.name.append(self.joint_names[i])
        
        self.joint_pub.publish(msg)

        if all_joints_reached:
            self.controller_timer.cancel()
            self.controller_timer = None 
            flag = Int16()
            flag.data = 1
            self.m3.publish(flag)
            self.get_logger().info('Reached target joint positions. Ready for new request.')


def main(args=None):
    rclpy.init(args=args)
    node = Mode3Controller()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
