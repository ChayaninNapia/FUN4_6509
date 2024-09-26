#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseStamped
import random

class RandomTargetPublisher(Node):
    def __init__(self):
        super().__init__('random_target_publisher')

        # Publisher that publishes random target positions to /target
        self.target_pub = self.create_publisher(PoseStamped, '/target', 10)

        # Timer to call publish_random_target periodically (every 1 second)
        self.timer = self.create_timer(1.0, self.publish_random_target)
        
        self.get_logger().info('Random Target Publisher has been started.')

    def publish_random_target(self):
        # Create a PoseStamped message to store the random target positions
        msg = PoseStamped()
        msg.header.stamp = self.get_clock().now().to_msg()

        # Generate random target positions within a defined range for x, y, z
        msg.pose.position.x = random.uniform(-10.0, 10.0)  # Random x position between -10 and 10
        msg.pose.position.y = random.uniform(-10.0, 10.0)  # Random y position between -10 and 10
        msg.pose.position.z = random.uniform(0.0, 5.0)     # Random z position between 0 and 5

        # Log the random target positions
        self.get_logger().info(f'Publishing random target: Position x={msg.pose.position.x}, y={msg.pose.position.y}, z={msg.pose.position.z}')

        # Publish the message
        self.target_pub.publish(msg)

def main(args=None):
    rclpy.init(args=args)
    node = RandomTargetPublisher()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
