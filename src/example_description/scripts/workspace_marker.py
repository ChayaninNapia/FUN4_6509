#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from visualization_msgs.msg import Marker
from sensor_msgs.msg import JointState
from geometry_msgs.msg import Point, TransformStamped
from std_msgs.msg import Header, ColorRGBA
import numpy as np
from tf2_ros import Buffer, TransformListener
from std_msgs.msg import Bool

class WorkspaceMarkerPublisher(Node):
    def __init__(self):
        super().__init__('workspace_marker_publisher')

        self.publisher_ = self.create_publisher(Marker, 'visualization_marker', 10)
        self.flag_subscriber = self.create_subscription(Bool, 'stop_plot', self.flag_callback,10)

        self.tf_buffer = Buffer()
        self.tf_listener = TransformListener(self.tf_buffer, self)
        self.timer_period = 0.01  
        self.timer = self.create_timer(self.timer_period, self.get_transform)
        self.target = [0.0, 0.0, 0.0]
        self.line_points = []

        self.flag = True

    def flag_callback(self, msg: Bool):
        self.flag = msg.data
        self.get_logger().info(f"Received flag: {self.flag}")
        
    def get_transform(self):
        
        if not self.flag:
            self.get_logger().info("stop plotting.")
            self.timer.cancel()
            return
        
        try:
      
            transform = self.tf_buffer.lookup_transform('link_0', 'end_effector', rclpy.time.Time())

            translation = transform.transform.translation
            self.target[0] = translation.x
            self.target[1] = translation.y
            self.target[2] = translation.z

           
            new_point = Point()
            new_point.x = float(self.target[0])
            new_point.y = float(self.target[1])
            new_point.z = float(self.target[2])
            self.line_points.append(new_point)

            self.publish_marker()

        except Exception as e:
            self.get_logger().warn(f"Could not transform: {str(e)}")

    def publish_marker(self):
        
        marker = Marker()
        marker.header = Header()
        marker.header.frame_id = "link_0"  
        marker.type = Marker.LINE_STRIP
        marker.action = Marker.ADD

        
        marker.points = self.line_points

        
        marker.scale.x = 0.02  

        
        marker.color = ColorRGBA()
        marker.color.r = 1.0  # Red
        marker.color.g = 0.0
        marker.color.b = 0.0
        marker.color.a = 1.0  

        self.publisher_.publish(marker)
        self.get_logger().info(f"Published marker with {len(self.line_points)} points")

def main(args=None):
    rclpy.init(args=args)
    node = WorkspaceMarkerPublisher()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
