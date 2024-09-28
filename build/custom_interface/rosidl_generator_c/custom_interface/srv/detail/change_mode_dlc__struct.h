// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_interface:srv/ChangeModeDlc.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACE__SRV__DETAIL__CHANGE_MODE_DLC__STRUCT_H_
#define CUSTOM_INTERFACE__SRV__DETAIL__CHANGE_MODE_DLC__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/ChangeModeDlc in the package custom_interface.
typedef struct custom_interface__srv__ChangeModeDlc_Request
{
  int32_t mode;
} custom_interface__srv__ChangeModeDlc_Request;

// Struct for a sequence of custom_interface__srv__ChangeModeDlc_Request.
typedef struct custom_interface__srv__ChangeModeDlc_Request__Sequence
{
  custom_interface__srv__ChangeModeDlc_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interface__srv__ChangeModeDlc_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/ChangeModeDlc in the package custom_interface.
typedef struct custom_interface__srv__ChangeModeDlc_Response
{
  /// Response:
  bool success;
} custom_interface__srv__ChangeModeDlc_Response;

// Struct for a sequence of custom_interface__srv__ChangeModeDlc_Response.
typedef struct custom_interface__srv__ChangeModeDlc_Response__Sequence
{
  custom_interface__srv__ChangeModeDlc_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interface__srv__ChangeModeDlc_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_INTERFACE__SRV__DETAIL__CHANGE_MODE_DLC__STRUCT_H_
