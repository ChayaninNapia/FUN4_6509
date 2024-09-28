// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_msg:msg/Qtarget.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSG__MSG__DETAIL__QTARGET__STRUCT_H_
#define CUSTOM_MSG__MSG__DETAIL__QTARGET__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'target_q'
// Member 'current_q'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/Qtarget in the package custom_msg.
typedef struct custom_msg__msg__Qtarget
{
  rosidl_runtime_c__double__Sequence target_q;
  rosidl_runtime_c__double__Sequence current_q;
} custom_msg__msg__Qtarget;

// Struct for a sequence of custom_msg__msg__Qtarget.
typedef struct custom_msg__msg__Qtarget__Sequence
{
  custom_msg__msg__Qtarget * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_msg__msg__Qtarget__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_MSG__MSG__DETAIL__QTARGET__STRUCT_H_
