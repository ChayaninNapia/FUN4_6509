// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from custom_msg:msg/Qtarget.idl
// generated code does not contain a copyright notice
#include "custom_msg/msg/detail/qtarget__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `target_q`
// Member `current_q`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
custom_msg__msg__Qtarget__init(custom_msg__msg__Qtarget * msg)
{
  if (!msg) {
    return false;
  }
  // target_q
  if (!rosidl_runtime_c__double__Sequence__init(&msg->target_q, 0)) {
    custom_msg__msg__Qtarget__fini(msg);
    return false;
  }
  // current_q
  if (!rosidl_runtime_c__double__Sequence__init(&msg->current_q, 0)) {
    custom_msg__msg__Qtarget__fini(msg);
    return false;
  }
  return true;
}

void
custom_msg__msg__Qtarget__fini(custom_msg__msg__Qtarget * msg)
{
  if (!msg) {
    return;
  }
  // target_q
  rosidl_runtime_c__double__Sequence__fini(&msg->target_q);
  // current_q
  rosidl_runtime_c__double__Sequence__fini(&msg->current_q);
}

bool
custom_msg__msg__Qtarget__are_equal(const custom_msg__msg__Qtarget * lhs, const custom_msg__msg__Qtarget * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // target_q
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->target_q), &(rhs->target_q)))
  {
    return false;
  }
  // current_q
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->current_q), &(rhs->current_q)))
  {
    return false;
  }
  return true;
}

bool
custom_msg__msg__Qtarget__copy(
  const custom_msg__msg__Qtarget * input,
  custom_msg__msg__Qtarget * output)
{
  if (!input || !output) {
    return false;
  }
  // target_q
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->target_q), &(output->target_q)))
  {
    return false;
  }
  // current_q
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->current_q), &(output->current_q)))
  {
    return false;
  }
  return true;
}

custom_msg__msg__Qtarget *
custom_msg__msg__Qtarget__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_msg__msg__Qtarget * msg = (custom_msg__msg__Qtarget *)allocator.allocate(sizeof(custom_msg__msg__Qtarget), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(custom_msg__msg__Qtarget));
  bool success = custom_msg__msg__Qtarget__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
custom_msg__msg__Qtarget__destroy(custom_msg__msg__Qtarget * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    custom_msg__msg__Qtarget__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
custom_msg__msg__Qtarget__Sequence__init(custom_msg__msg__Qtarget__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_msg__msg__Qtarget * data = NULL;

  if (size) {
    data = (custom_msg__msg__Qtarget *)allocator.zero_allocate(size, sizeof(custom_msg__msg__Qtarget), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = custom_msg__msg__Qtarget__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        custom_msg__msg__Qtarget__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
custom_msg__msg__Qtarget__Sequence__fini(custom_msg__msg__Qtarget__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      custom_msg__msg__Qtarget__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

custom_msg__msg__Qtarget__Sequence *
custom_msg__msg__Qtarget__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_msg__msg__Qtarget__Sequence * array = (custom_msg__msg__Qtarget__Sequence *)allocator.allocate(sizeof(custom_msg__msg__Qtarget__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = custom_msg__msg__Qtarget__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
custom_msg__msg__Qtarget__Sequence__destroy(custom_msg__msg__Qtarget__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    custom_msg__msg__Qtarget__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
custom_msg__msg__Qtarget__Sequence__are_equal(const custom_msg__msg__Qtarget__Sequence * lhs, const custom_msg__msg__Qtarget__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!custom_msg__msg__Qtarget__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
custom_msg__msg__Qtarget__Sequence__copy(
  const custom_msg__msg__Qtarget__Sequence * input,
  custom_msg__msg__Qtarget__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(custom_msg__msg__Qtarget);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    custom_msg__msg__Qtarget * data =
      (custom_msg__msg__Qtarget *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!custom_msg__msg__Qtarget__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          custom_msg__msg__Qtarget__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!custom_msg__msg__Qtarget__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
