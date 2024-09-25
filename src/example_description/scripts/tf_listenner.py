#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from tf2_ros import Buffer, TransformListener
from geometry_msgs.msg import TransformStamped

class TFSubscriber(Node):
    def __init__(self):
        super().__init__('tf_subscriber')

        # Create a buffer and listener to receive TF2 transforms
        self.tf_buffer = Buffer()
        self.tf_listener = TransformListener(self.tf_buffer, self)

        # Timer to call the callback periodically
        self.timer = self.create_timer(1.0, self.get_transform)  # 1.0 seconds

    def get_transform(self):
        try:
            # Lookup the transform between 'link_0' and 'end_effector'
            transform = self.tf_buffer.lookup_transform('link_0', 'end_effector', rclpy.time.Time())

            # Print the translation and rotation information
            self.print_transform(transform)

        except Exception as e:
            self.get_logger().warn(f"Could not transform: {str(e)}")

    def print_transform(self, transform: TransformStamped):
        translation = transform.transform.translation
        rotation = transform.transform.rotation

        # Print translation
        self.get_logger().info(f"Translation: x = {translation.x}, y = {translation.y}, z = {translation.z}")

        # Print rotation in quaternion
        self.get_logger().info(f"Rotation (Quaternion): x = {rotation.x}, y = {rotation.y}, z = {rotation.z}, w = {rotation.w}")

        # You can convert the quaternion to Euler angles (roll, pitch, yaw) if needed using helper functions

def main(args=None):
    rclpy.init(args=args)
    node = TFSubscriber()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
