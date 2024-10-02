// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from robot_action:srv/GenTarget.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_ACTION__SRV__DETAIL__GEN_TARGET__STRUCT_H_
#define ROBOT_ACTION__SRV__DETAIL__GEN_TARGET__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/GenTarget in the package robot_action.
typedef struct robot_action__srv__GenTarget_Request
{
  bool trigger;
} robot_action__srv__GenTarget_Request;

// Struct for a sequence of robot_action__srv__GenTarget_Request.
typedef struct robot_action__srv__GenTarget_Request__Sequence
{
  robot_action__srv__GenTarget_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robot_action__srv__GenTarget_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'taskspace'
#include "geometry_msgs/msg/detail/pose_stamped__struct.h"

/// Struct defined in srv/GenTarget in the package robot_action.
typedef struct robot_action__srv__GenTarget_Response
{
  /// Response
  geometry_msgs__msg__PoseStamped taskspace;
} robot_action__srv__GenTarget_Response;

// Struct for a sequence of robot_action__srv__GenTarget_Response.
typedef struct robot_action__srv__GenTarget_Response__Sequence
{
  robot_action__srv__GenTarget_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robot_action__srv__GenTarget_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROBOT_ACTION__SRV__DETAIL__GEN_TARGET__STRUCT_H_
