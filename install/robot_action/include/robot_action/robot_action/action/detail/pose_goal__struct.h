// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from robot_action:action/PoseGoal.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_ACTION__ACTION__DETAIL__POSE_GOAL__STRUCT_H_
#define ROBOT_ACTION__ACTION__DETAIL__POSE_GOAL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'task'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in action/PoseGoal in the package robot_action.
typedef struct robot_action__action__PoseGoal_Goal
{
  /// 0 for configuration space, 1 for task space, 3 velocity_control_base 4 velocity_control_end_effector
  int16_t task_type;
  rosidl_runtime_c__double__Sequence task;
} robot_action__action__PoseGoal_Goal;

// Struct for a sequence of robot_action__action__PoseGoal_Goal.
typedef struct robot_action__action__PoseGoal_Goal__Sequence
{
  robot_action__action__PoseGoal_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robot_action__action__PoseGoal_Goal__Sequence;


// Constants defined in the message

/// Struct defined in action/PoseGoal in the package robot_action.
typedef struct robot_action__action__PoseGoal_Result
{
  bool success;
} robot_action__action__PoseGoal_Result;

// Struct for a sequence of robot_action__action__PoseGoal_Result.
typedef struct robot_action__action__PoseGoal_Result__Sequence
{
  robot_action__action__PoseGoal_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robot_action__action__PoseGoal_Result__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'current_q'
// already included above
// #include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in action/PoseGoal in the package robot_action.
typedef struct robot_action__action__PoseGoal_Feedback
{
  rosidl_runtime_c__double__Sequence current_q;
} robot_action__action__PoseGoal_Feedback;

// Struct for a sequence of robot_action__action__PoseGoal_Feedback.
typedef struct robot_action__action__PoseGoal_Feedback__Sequence
{
  robot_action__action__PoseGoal_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robot_action__action__PoseGoal_Feedback__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "robot_action/action/detail/pose_goal__struct.h"

/// Struct defined in action/PoseGoal in the package robot_action.
typedef struct robot_action__action__PoseGoal_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  robot_action__action__PoseGoal_Goal goal;
} robot_action__action__PoseGoal_SendGoal_Request;

// Struct for a sequence of robot_action__action__PoseGoal_SendGoal_Request.
typedef struct robot_action__action__PoseGoal_SendGoal_Request__Sequence
{
  robot_action__action__PoseGoal_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robot_action__action__PoseGoal_SendGoal_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/PoseGoal in the package robot_action.
typedef struct robot_action__action__PoseGoal_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} robot_action__action__PoseGoal_SendGoal_Response;

// Struct for a sequence of robot_action__action__PoseGoal_SendGoal_Response.
typedef struct robot_action__action__PoseGoal_SendGoal_Response__Sequence
{
  robot_action__action__PoseGoal_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robot_action__action__PoseGoal_SendGoal_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/PoseGoal in the package robot_action.
typedef struct robot_action__action__PoseGoal_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} robot_action__action__PoseGoal_GetResult_Request;

// Struct for a sequence of robot_action__action__PoseGoal_GetResult_Request.
typedef struct robot_action__action__PoseGoal_GetResult_Request__Sequence
{
  robot_action__action__PoseGoal_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robot_action__action__PoseGoal_GetResult_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "robot_action/action/detail/pose_goal__struct.h"

/// Struct defined in action/PoseGoal in the package robot_action.
typedef struct robot_action__action__PoseGoal_GetResult_Response
{
  int8_t status;
  robot_action__action__PoseGoal_Result result;
} robot_action__action__PoseGoal_GetResult_Response;

// Struct for a sequence of robot_action__action__PoseGoal_GetResult_Response.
typedef struct robot_action__action__PoseGoal_GetResult_Response__Sequence
{
  robot_action__action__PoseGoal_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robot_action__action__PoseGoal_GetResult_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "robot_action/action/detail/pose_goal__struct.h"

/// Struct defined in action/PoseGoal in the package robot_action.
typedef struct robot_action__action__PoseGoal_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  robot_action__action__PoseGoal_Feedback feedback;
} robot_action__action__PoseGoal_FeedbackMessage;

// Struct for a sequence of robot_action__action__PoseGoal_FeedbackMessage.
typedef struct robot_action__action__PoseGoal_FeedbackMessage__Sequence
{
  robot_action__action__PoseGoal_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robot_action__action__PoseGoal_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROBOT_ACTION__ACTION__DETAIL__POSE_GOAL__STRUCT_H_
