#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from custom_interface.srv import ChangeMode

class RobotServer(Node):
    def __init__(self):
        super().__init__('mode_service')
        self.srv = self.create_service(ChangeMode, 'change_mode', self.change_mode_callback)
        self.mode = 0  
        

    def change_mode_callback(self, request, response):
        mode_name = ["Inverse Pose Kinematics", "Teleoperation", "Auto"]
        if request.mode in [1, 2, 3]:
            self.mode = request.mode
            self.get_logger().info(f'Changing mode to {self.mode} : {mode_name[request.mode -1]}')
            response.success = True
        else:
            self.get_logger().warn(f'Received invalid mode: {request.mode}')
            response.success = False
        return response

def main(args=None):
    rclpy.init(args=args)
    node = RobotServer()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
