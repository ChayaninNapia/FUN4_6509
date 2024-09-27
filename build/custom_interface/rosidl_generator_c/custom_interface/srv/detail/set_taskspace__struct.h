// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_interface:srv/SetTaskspace.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACE__SRV__DETAIL__SET_TASKSPACE__STRUCT_H_
#define CUSTOM_INTERFACE__SRV__DETAIL__SET_TASKSPACE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/SetTaskspace in the package custom_interface.
typedef struct custom_interface__srv__SetTaskspace_Request
{
  double x;
  double y;
  double z;
} custom_interface__srv__SetTaskspace_Request;

// Struct for a sequence of custom_interface__srv__SetTaskspace_Request.
typedef struct custom_interface__srv__SetTaskspace_Request__Sequence
{
  custom_interface__srv__SetTaskspace_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interface__srv__SetTaskspace_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/SetTaskspace in the package custom_interface.
typedef struct custom_interface__srv__SetTaskspace_Response
{
  bool success;
} custom_interface__srv__SetTaskspace_Response;

// Struct for a sequence of custom_interface__srv__SetTaskspace_Response.
typedef struct custom_interface__srv__SetTaskspace_Response__Sequence
{
  custom_interface__srv__SetTaskspace_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interface__srv__SetTaskspace_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_INTERFACE__SRV__DETAIL__SET_TASKSPACE__STRUCT_H_
