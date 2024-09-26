#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseStamped
from sensor_msgs.msg import JointState
from math import pi
import roboticstoolbox as rtb
from spatialmath import SE3

class JointStateFollower(Node):
    def __init__(self):
        super().__init__('joint_state_follower')

        # Publisher for joint states
        self.joint_pub = self.create_publisher(JointState, '/joint_states', 10)

        # Subscriber for target poses
        self.target_sub = self.create_subscription(
            PoseStamped,
            '/target',
            self.target_callback,
            10
        )

        # Initialize the robot model with 4 joints
        self.robot = rtb.DHRobot(
            [
                rtb.RevoluteMDH(d=0.2, alpha=0, offset=0),           # Joint 1
                rtb.RevoluteMDH(alpha=-pi/2, offset=-pi/2),          # Joint 2
                rtb.RevoluteMDH(a=0.25, d=-0.02, offset=pi/2),       # Joint 3
                rtb.RevoluteMDH(alpha=pi/2, d=0.28, offset=0)        # Joint 4 (End-Effector)
            ],
            name="robot"
        )

        # Define joint names for the first three joints
        self.joint_names = ["joint_1", "joint_2", "joint_3"]

        # Initialize current joint state (for potential future use)
        self.current_joint_state = [0.0, 0.0, 0.0]

        self.get_logger().info('Joint State Follower Node has been started.')

    def target_callback(self, msg: PoseStamped):

        self.get_logger().info('Received new target pose.')

        # Extract position from PoseStamped
        x = msg.pose.position.x
        y = msg.pose.position.y
        z = msg.pose.position.z

        # Create desired_pose with only translation (ignore orientation)
        desired_pose = SE3(x, y, z)

        # Define the mask: [x, y, z, roll, pitch, yaw]
        mask = [1, 1, 1, 0, 0, 0]  # Only consider translation

        # Compute inverse kinematics
        solution = self.robot.ikine_LM(desired_pose, mask=mask)

        if solution.success:
            # Extract the first three joint angles
            q_ik = solution.q[:3]
            self.get_logger().info(f"IK Solution found: {q_ik}")

            # Create JointState message
            joint_msg = JointState()
            joint_msg.header.stamp = self.get_clock().now().to_msg()
            joint_msg.name = self.joint_names
            joint_msg.position = q_ik.tolist()

            # Publish the JointState message
            self.joint_pub.publish(joint_msg)
            self.get_logger().info("Published joint states for joint_1, joint_2, joint_3.")
        else:
            self.get_logger().warn("Inverse Kinematics did not find a solution for the received target.")

def main(args=None):
    rclpy.init(args=args)
    node = JointStateFollower()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
