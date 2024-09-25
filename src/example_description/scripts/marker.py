#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from visualization_msgs.msg import Marker
from geometry_msgs.msg import Point
from std_msgs.msg import Header, ColorRGBA

class WorkspaceMarkerPublisher(Node):
    def __init__(self):
        super().__init__('workspace_marker_publisher')
        self.publisher_ = self.create_publisher(Marker, 'visualization_marker', 10)
        self.timer_period = 0.01  # seconds
        self.timer = self.create_timer(self.timer_period, self.publish_marker)
        self.count = 0
        self.line_points = []  # To store the points for the line

    def publish_marker(self):
        # Define a marker for drawing a line (LINE_STRIP)
        marker = Marker()
        marker.header = Header()
        marker.header.frame_id = "link_0"  # Replace with your robot's reference frame
        marker.type = Marker.LINE_STRIP
        marker.action = Marker.ADD

        # Set marker scale (thickness of the line)
        marker.scale.x = 0.02  # Line thickness

        # Set marker color (RGBA)
        marker.color = ColorRGBA()
        marker.color.r = 1.0  # Red
        marker.color.g = 0.0
        marker.color.b = 0.0
        marker.color.a = 1.0  # 1.0 means fully visible

        # Define a new point in the trajectory
        new_point = Point()
        new_point.x = 0.5 + self.count * 0.001  # X-coordinate changes over time
        new_point.y = 0.5  # Constant Y-coordinate
        new_point.z = 0.5  # Constant Z-coordinate

        # Add the new point to the line_points list
        self.line_points.append(new_point)

        # Assign the points to the marker
        marker.points = self.line_points

        # Publish the marker (the line)
        self.publisher_.publish(marker)
        self.get_logger().info(f"Published a marker with {len(self.line_points)} points")
        
        self.count += 1

def main(args=None):
    rclpy.init(args=args)
    node = WorkspaceMarkerPublisher()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
