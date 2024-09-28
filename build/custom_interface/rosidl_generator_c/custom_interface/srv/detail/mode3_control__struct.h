// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_interface:srv/Mode3Control.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACE__SRV__DETAIL__MODE3_CONTROL__STRUCT_H_
#define CUSTOM_INTERFACE__SRV__DETAIL__MODE3_CONTROL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'target_joint_positions'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in srv/Mode3Control in the package custom_interface.
typedef struct custom_interface__srv__Mode3Control_Request
{
  /// Request
  /// Array of target joint positions
  rosidl_runtime_c__double__Sequence target_joint_positions;
} custom_interface__srv__Mode3Control_Request;

// Struct for a sequence of custom_interface__srv__Mode3Control_Request.
typedef struct custom_interface__srv__Mode3Control_Request__Sequence
{
  custom_interface__srv__Mode3Control_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interface__srv__Mode3Control_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/Mode3Control in the package custom_interface.
typedef struct custom_interface__srv__Mode3Control_Response
{
  /// Indicates if the mode 3 controller successfully moved to the target joint positions
  bool success;
  /// Optional message providing more detail (success or failure)
  rosidl_runtime_c__String message;
} custom_interface__srv__Mode3Control_Response;

// Struct for a sequence of custom_interface__srv__Mode3Control_Response.
typedef struct custom_interface__srv__Mode3Control_Response__Sequence
{
  custom_interface__srv__Mode3Control_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interface__srv__Mode3Control_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_INTERFACE__SRV__DETAIL__MODE3_CONTROL__STRUCT_H_
