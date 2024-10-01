import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument, GroupAction 
import xacro    
from launch.conditions import IfCondition
from launch.substitutions import LaunchConfiguration, PythonExpression


def generate_launch_description():

    # Declare the mode launch argument
    mode_arg = DeclareLaunchArgument(
        'mode',
        default_value='1',
        description='Mode to decide which nodes to launch'
    )
    
    # Get the package directory
    pkg = get_package_share_directory('robot_control')
    
    # Paths for RViz and the robot description
    rviz_path = os.path.join(pkg, 'config', 'my_display.rviz')
    path_description = os.path.join(pkg, 'urdf', 'my-robot.xacro')
    
    # Process the xacro file
    robot_desc_xml = xacro.process_file(path_description).toxml()
    
    # Define nodes
    rviz = Node(
        package='rviz2',
        executable='rviz2',
        name='rviz',
        arguments=['-d', rviz_path],
        output='screen'
    )

    robot_state_publisher = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        output='screen',
        parameters=[{'robot_description': robot_desc_xml}]
    )

    joint_state_publisher_gui = Node(
        package='joint_state_publisher_gui',
        executable='joint_state_publisher_gui'
    )

    action_client_node = Node(
        package='robot_control',
        executable='robot_action_client.py',
        output='screen'
    )
    
    action_server_node = Node(
        package='robot_control',
        executable='robot_action_server.py',
        output='screen'
    )
    
    robot_server_node = Node(
        package='robot_control',
        executable='robot_server.py',
        output='screen'
    )
    
    random_target_node = Node(
        package='robot_control',
        executable='random_target.py',
        output='screen'
    )
    
    workspce_plot_node = Node(
        package='robot_control',
        executable='workspace_plot.py',
        output='screen'
    )
    workspce_move_node = Node(
        package='robot_control',
        executable='workspace_move.py',
        output='screen'
    )
    

    # Create a launch description and add actions
    ld = LaunchDescription()
    
    # Add the mode argument
    ld.add_action(mode_arg)

    # Group nodes to be launched when mode is '1'
    mode_1_group = GroupAction(
        actions=[
            Node(
            package='robot_control',
            executable='random_target.py',
            output='screen',
            parameters=[{'mode': LaunchConfiguration('mode')}], 
            ),
            rviz,
            robot_state_publisher,
            joint_state_publisher_gui
        ],
        condition=IfCondition(PythonExpression(["'", LaunchConfiguration('mode'), "' == '1'"]))
    )

    # Group nodes to be launched when mode is '2'
    mode_2_group = GroupAction(
        actions=[
            robot_server_node,
            action_server_node,
            Node(
            package='robot_control',
            executable='random_target.py',
            output='screen',
            parameters=[{'mode': LaunchConfiguration('mode')}], 
            ),
            robot_state_publisher,
            rviz
        ],
        condition=IfCondition(PythonExpression(["'", LaunchConfiguration('mode'), "' == '2'"]))
    )
    
    mode_0_group = GroupAction(
        actions=[
            robot_state_publisher,
            rviz,
            workspce_move_node,
            workspce_plot_node
        ],
        condition=IfCondition(PythonExpression(["'", LaunchConfiguration('mode'), "' == '0'"]))
    )
    
    # Add groups to launch description
    ld.add_action(mode_0_group)
    ld.add_action(mode_1_group)
    ld.add_action(mode_2_group)
    

    return ld
