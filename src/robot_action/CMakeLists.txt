cmake_minimum_required(VERSION 3.8)
project(robot_action)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(rosidl_default_generators REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)
rosidl_generate_interfaces(${PROJECT_NAME}
  "action/PoseGoal.action"
  "srv/GenTarget.srv"
  "srv/ChangeMode.srv"
  "srv/SetTaskspace.srv"
  DEPENDENCIES geometry_msgs 
)
ament_export_dependencies(rosidl_default_runtime)

ament_package()
