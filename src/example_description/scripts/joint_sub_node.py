#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from tf2_ros import Buffer, TransformListener
from geometry_msgs.msg import TransformStamped
import numpy as np
import tf_transformations
from geometry_msgs.msg import PoseStamped

class TFSubscriber(Node):
    def __init__(self):
        super().__init__('end_effector_subscriber_node')

        
        self.tf_buffer = Buffer()
        self.tf_listener = TransformListener(self.tf_buffer, self)
        self.pose_pub = self.create_publisher(PoseStamped, '/end_effector', 10)

        
        self.timer = self.create_timer(0.1, self.get_transform)  

    def get_transform(self):
        try:
            transform = self.tf_buffer.lookup_transform('link_0', 'end_effector', rclpy.time.Time())
            self.print_transform_matrix(transform)

        except Exception as e:
            self.get_logger().warn(f"Could not transform: {str(e)}")

    def print_transform_matrix(self, transform: TransformStamped):
        translation = transform.transform.translation
        rotation = transform.transform.rotation

        quaternion = [rotation.x, rotation.y, rotation.z, rotation.w]
        rotation_matrix = tf_transformations.quaternion_matrix(quaternion)

        rotation_matrix[0, 3] = translation.x
        rotation_matrix[1, 3] = translation.y
        rotation_matrix[2, 3] = translation.z

        msg = PoseStamped()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.header.frame_id = "link_0"
        msg.pose.position.x = translation.x
        msg.pose.position.y = translation.y
        msg.pose.position.z = translation.z
        self.pose_pub.publish(msg)
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
