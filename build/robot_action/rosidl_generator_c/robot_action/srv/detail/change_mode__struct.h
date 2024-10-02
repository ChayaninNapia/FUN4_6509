// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from robot_action:srv/ChangeMode.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_ACTION__SRV__DETAIL__CHANGE_MODE__STRUCT_H_
#define ROBOT_ACTION__SRV__DETAIL__CHANGE_MODE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/ChangeMode in the package robot_action.
typedef struct robot_action__srv__ChangeMode_Request
{
  int32_t mode;
} robot_action__srv__ChangeMode_Request;

// Struct for a sequence of robot_action__srv__ChangeMode_Request.
typedef struct robot_action__srv__ChangeMode_Request__Sequence
{
  robot_action__srv__ChangeMode_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robot_action__srv__ChangeMode_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/ChangeMode in the package robot_action.
typedef struct robot_action__srv__ChangeMode_Response
{
  /// Response:
  bool success;
} robot_action__srv__ChangeMode_Response;

// Struct for a sequence of robot_action__srv__ChangeMode_Response.
typedef struct robot_action__srv__ChangeMode_Response__Sequence
{
  robot_action__srv__ChangeMode_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robot_action__srv__ChangeMode_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROBOT_ACTION__SRV__DETAIL__CHANGE_MODE__STRUCT_H_
