#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from tf2_ros import Buffer, TransformListener
from geometry_msgs.msg import TransformStamped
import numpy as np
import tf_transformations  # Make sure to install the tf_transformations package

class TFSubscriber(Node):
    def __init__(self):
        super().__init__('tf_subscriber')

        # Create a buffer and listener to receive TF2 transforms
        self.tf_buffer = Buffer()
        self.tf_listener = TransformListener(self.tf_buffer, self)

        # Timer to call the callback periodically
        self.timer = self.create_timer(0.1, self.get_transform)  # 1.0 seconds

    def get_transform(self):
        try:
            # Lookup the transform between 'link_0' and 'end_effector'
            transform = self.tf_buffer.lookup_transform('link_0', 'end_effector', rclpy.time.Time())

            # Print the full transformation matrix
            self.print_transform_matrix(transform)

        except Exception as e:
            self.get_logger().warn(f"Could not transform: {str(e)}")

    def print_transform_matrix(self, transform: TransformStamped):
        translation = transform.transform.translation
        rotation = transform.transform.rotation

        # Convert quaternion to rotation matrix
        quaternion = [rotation.x, rotation.y, rotation.z, rotation.w]
        rotation_matrix = tf_transformations.quaternion_matrix(quaternion)

        # Add translation to the rotation matrix to form the full transformation matrix
        rotation_matrix[0, 3] = translation.x
        rotation_matrix[1, 3] = translation.y
        rotation_matrix[2, 3] = translation.z

        # Print the transformation matrix
        self.get_logger().info("Transformation Matrix:")
        self.get_logger().info(f"\n{rotation_matrix}")

def main(args=None):
    rclpy.init(args=args)
    node = TFSubscriber()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
