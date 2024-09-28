// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from custom_msg:msg/Qtarget.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "custom_msg/msg/detail/qtarget__rosidl_typesupport_introspection_c.h"
#include "custom_msg/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "custom_msg/msg/detail/qtarget__functions.h"
#include "custom_msg/msg/detail/qtarget__struct.h"


// Include directives for member types
// Member `target_q`
// Member `current_q`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void custom_msg__msg__Qtarget__rosidl_typesupport_introspection_c__Qtarget_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  custom_msg__msg__Qtarget__init(message_memory);
}

void custom_msg__msg__Qtarget__rosidl_typesupport_introspection_c__Qtarget_fini_function(void * message_memory)
{
  custom_msg__msg__Qtarget__fini(message_memory);
}

size_t custom_msg__msg__Qtarget__rosidl_typesupport_introspection_c__size_function__Qtarget__target_q(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * custom_msg__msg__Qtarget__rosidl_typesupport_introspection_c__get_const_function__Qtarget__target_q(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * custom_msg__msg__Qtarget__rosidl_typesupport_introspection_c__get_function__Qtarget__target_q(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void custom_msg__msg__Qtarget__rosidl_typesupport_introspection_c__fetch_function__Qtarget__target_q(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    custom_msg__msg__Qtarget__rosidl_typesupport_introspection_c__get_const_function__Qtarget__target_q(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void custom_msg__msg__Qtarget__rosidl_typesupport_introspection_c__assign_function__Qtarget__target_q(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    custom_msg__msg__Qtarget__rosidl_typesupport_introspection_c__get_function__Qtarget__target_q(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool custom_msg__msg__Qtarget__rosidl_typesupport_introspection_c__resize_function__Qtarget__target_q(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

size_t custom_msg__msg__Qtarget__rosidl_typesupport_introspection_c__size_function__Qtarget__current_q(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * custom_msg__msg__Qtarget__rosidl_typesupport_introspection_c__get_const_function__Qtarget__current_q(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * custom_msg__msg__Qtarget__rosidl_typesupport_introspection_c__get_function__Qtarget__current_q(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void custom_msg__msg__Qtarget__rosidl_typesupport_introspection_c__fetch_function__Qtarget__current_q(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    custom_msg__msg__Qtarget__rosidl_typesupport_introspection_c__get_const_function__Qtarget__current_q(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void custom_msg__msg__Qtarget__rosidl_typesupport_introspection_c__assign_function__Qtarget__current_q(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    custom_msg__msg__Qtarget__rosidl_typesupport_introspection_c__get_function__Qtarget__current_q(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool custom_msg__msg__Qtarget__rosidl_typesupport_introspection_c__resize_function__Qtarget__current_q(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember custom_msg__msg__Qtarget__rosidl_typesupport_introspection_c__Qtarget_message_member_array[2] = {
  {
    "target_q",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_msg__msg__Qtarget, target_q),  // bytes offset in struct
    NULL,  // default value
    custom_msg__msg__Qtarget__rosidl_typesupport_introspection_c__size_function__Qtarget__target_q,  // size() function pointer
    custom_msg__msg__Qtarget__rosidl_typesupport_introspection_c__get_const_function__Qtarget__target_q,  // get_const(index) function pointer
    custom_msg__msg__Qtarget__rosidl_typesupport_introspection_c__get_function__Qtarget__target_q,  // get(index) function pointer
    custom_msg__msg__Qtarget__rosidl_typesupport_introspection_c__fetch_function__Qtarget__target_q,  // fetch(index, &value) function pointer
    custom_msg__msg__Qtarget__rosidl_typesupport_introspection_c__assign_function__Qtarget__target_q,  // assign(index, value) function pointer
    custom_msg__msg__Qtarget__rosidl_typesupport_introspection_c__resize_function__Qtarget__target_q  // resize(index) function pointer
  },
  {
    "current_q",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_msg__msg__Qtarget, current_q),  // bytes offset in struct
    NULL,  // default value
    custom_msg__msg__Qtarget__rosidl_typesupport_introspection_c__size_function__Qtarget__current_q,  // size() function pointer
    custom_msg__msg__Qtarget__rosidl_typesupport_introspection_c__get_const_function__Qtarget__current_q,  // get_const(index) function pointer
    custom_msg__msg__Qtarget__rosidl_typesupport_introspection_c__get_function__Qtarget__current_q,  // get(index) function pointer
    custom_msg__msg__Qtarget__rosidl_typesupport_introspection_c__fetch_function__Qtarget__current_q,  // fetch(index, &value) function pointer
    custom_msg__msg__Qtarget__rosidl_typesupport_introspection_c__assign_function__Qtarget__current_q,  // assign(index, value) function pointer
    custom_msg__msg__Qtarget__rosidl_typesupport_introspection_c__resize_function__Qtarget__current_q  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers custom_msg__msg__Qtarget__rosidl_typesupport_introspection_c__Qtarget_message_members = {
  "custom_msg__msg",  // message namespace
  "Qtarget",  // message name
  2,  // number of fields
  sizeof(custom_msg__msg__Qtarget),
  custom_msg__msg__Qtarget__rosidl_typesupport_introspection_c__Qtarget_message_member_array,  // message members
  custom_msg__msg__Qtarget__rosidl_typesupport_introspection_c__Qtarget_init_function,  // function to initialize message memory (memory has to be allocated)
  custom_msg__msg__Qtarget__rosidl_typesupport_introspection_c__Qtarget_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t custom_msg__msg__Qtarget__rosidl_typesupport_introspection_c__Qtarget_message_type_support_handle = {
  0,
  &custom_msg__msg__Qtarget__rosidl_typesupport_introspection_c__Qtarget_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_custom_msg
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_msg, msg, Qtarget)() {
  if (!custom_msg__msg__Qtarget__rosidl_typesupport_introspection_c__Qtarget_message_type_support_handle.typesupport_identifier) {
    custom_msg__msg__Qtarget__rosidl_typesupport_introspection_c__Qtarget_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &custom_msg__msg__Qtarget__rosidl_typesupport_introspection_c__Qtarget_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
