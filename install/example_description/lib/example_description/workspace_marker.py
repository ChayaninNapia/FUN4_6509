#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from visualization_msgs.msg import Marker
from sensor_msgs.msg import JointState
from geometry_msgs.msg import Point, TransformStamped
from std_msgs.msg import Header, ColorRGBA
import numpy as np
from tf2_ros import Buffer, TransformListener

class WorkspaceMarkerPublisher(Node):
    def __init__(self):
        super().__init__('workspace_marker_publisher')

        # Publisher for the marker
        self.publisher_ = self.create_publisher(Marker, 'visualization_marker', 10)

        # Create a buffer and listener to receive TF2 transforms
        self.tf_buffer = Buffer()
        self.tf_listener = TransformListener(self.tf_buffer, self)

        # Timer to call the callback periodically for the transform and marker publishing
        self.timer_period = 0.01  # seconds
        self.timer = self.create_timer(self.timer_period, self.get_transform)
        
        # Store the target position (end-effector position)
        self.target = [0.0, 0.0, 0.0]

        # Initialize line_points list to store points for the line strip
        self.line_points = []

    def get_transform(self):
        try:
            # Lookup the transform between 'link_0' and 'end_effector'
            transform = self.tf_buffer.lookup_transform('link_0', 'end_effector', rclpy.time.Time())

            # Update the target position (translation)
            translation = transform.transform.translation
            self.target[0] = translation.x
            self.target[1] = translation.y
            self.target[2] = translation.z

            # Add the new point to the line_points list
            new_point = Point()
            new_point.x = float(self.target[0])
            new_point.y = float(self.target[1])
            new_point.z = float(self.target[2])
            self.line_points.append(new_point)

            # Publish the updated marker
            self.publish_marker()

        except Exception as e:
            self.get_logger().warn(f"Could not transform: {str(e)}")

    def publish_marker(self):
        # Define a marker for drawing a line (LINE_STRIP)
        marker = Marker()
        marker.header = Header()
        marker.header.frame_id = "link_0"  # The base frame of your robot
        marker.type = Marker.LINE_STRIP
        marker.action = Marker.ADD

        # Assign the points to the marker (the line will be drawn from the points in line_points)
        marker.points = self.line_points

        # Set marker scale (thickness of the line)
        marker.scale.x = 0.02  # Line thickness

        # Set marker color (RGBA)
        marker.color = ColorRGBA()
        marker.color.r = 1.0  # Red
        marker.color.g = 0.0
        marker.color.b = 0.0
        marker.color.a = 1.0  # 1.0 means fully visible

        # Publish the marker (the line)
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
