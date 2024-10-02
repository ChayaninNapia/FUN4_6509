// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from robot_action:action/PoseGoal.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_ACTION__ACTION__DETAIL__POSE_GOAL__TRAITS_HPP_
#define ROBOT_ACTION__ACTION__DETAIL__POSE_GOAL__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "robot_action/action/detail/pose_goal__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace robot_action
{

namespace action
{

inline void to_flow_style_yaml(
  const PoseGoal_Goal & msg,
  std::ostream & out)
{
  out << "{";
  // member: task_type
  {
    out << "task_type: ";
    rosidl_generator_traits::value_to_yaml(msg.task_type, out);
    out << ", ";
  }

  // member: task
  {
    if (msg.task.size() == 0) {
      out << "task: []";
    } else {
      out << "task: [";
      size_t pending_items = msg.task.size();
      for (auto item : msg.task) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const PoseGoal_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: task_type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "task_type: ";
    rosidl_generator_traits::value_to_yaml(msg.task_type, out);
    out << "\n";
  }

  // member: task
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.task.size() == 0) {
      out << "task: []\n";
    } else {
      out << "task:\n";
      for (auto item : msg.task) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const PoseGoal_Goal & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace robot_action

namespace rosidl_generator_traits
{

[[deprecated("use robot_action::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const robot_action::action::PoseGoal_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  robot_action::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use robot_action::action::to_yaml() instead")]]
inline std::string to_yaml(const robot_action::action::PoseGoal_Goal & msg)
{
  return robot_action::action::to_yaml(msg);
}

template<>
inline const char * data_type<robot_action::action::PoseGoal_Goal>()
{
  return "robot_action::action::PoseGoal_Goal";
}

template<>
inline const char * name<robot_action::action::PoseGoal_Goal>()
{
  return "robot_action/action/PoseGoal_Goal";
}

template<>
struct has_fixed_size<robot_action::action::PoseGoal_Goal>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<robot_action::action::PoseGoal_Goal>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<robot_action::action::PoseGoal_Goal>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace robot_action
{

namespace action
{

inline void to_flow_style_yaml(
  const PoseGoal_Result & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const PoseGoal_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const PoseGoal_Result & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace robot_action

namespace rosidl_generator_traits
{

[[deprecated("use robot_action::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const robot_action::action::PoseGoal_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  robot_action::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use robot_action::action::to_yaml() instead")]]
inline std::string to_yaml(const robot_action::action::PoseGoal_Result & msg)
{
  return robot_action::action::to_yaml(msg);
}

template<>
inline const char * data_type<robot_action::action::PoseGoal_Result>()
{
  return "robot_action::action::PoseGoal_Result";
}

template<>
inline const char * name<robot_action::action::PoseGoal_Result>()
{
  return "robot_action/action/PoseGoal_Result";
}

template<>
struct has_fixed_size<robot_action::action::PoseGoal_Result>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<robot_action::action::PoseGoal_Result>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<robot_action::action::PoseGoal_Result>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace robot_action
{

namespace action
{

inline void to_flow_style_yaml(
  const PoseGoal_Feedback & msg,
  std::ostream & out)
{
  out << "{";
  // member: current_q
  {
    if (msg.current_q.size() == 0) {
      out << "current_q: []";
    } else {
      out << "current_q: [";
      size_t pending_items = msg.current_q.size();
      for (auto item : msg.current_q) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const PoseGoal_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: current_q
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.current_q.size() == 0) {
      out << "current_q: []\n";
    } else {
      out << "current_q:\n";
      for (auto item : msg.current_q) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const PoseGoal_Feedback & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace robot_action

namespace rosidl_generator_traits
{

[[deprecated("use robot_action::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const robot_action::action::PoseGoal_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  robot_action::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use robot_action::action::to_yaml() instead")]]
inline std::string to_yaml(const robot_action::action::PoseGoal_Feedback & msg)
{
  return robot_action::action::to_yaml(msg);
}

template<>
inline const char * data_type<robot_action::action::PoseGoal_Feedback>()
{
  return "robot_action::action::PoseGoal_Feedback";
}

template<>
inline const char * name<robot_action::action::PoseGoal_Feedback>()
{
  return "robot_action/action/PoseGoal_Feedback";
}

template<>
struct has_fixed_size<robot_action::action::PoseGoal_Feedback>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<robot_action::action::PoseGoal_Feedback>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<robot_action::action::PoseGoal_Feedback>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'goal'
#include "robot_action/action/detail/pose_goal__traits.hpp"

namespace robot_action
{

namespace action
{

inline void to_flow_style_yaml(
  const PoseGoal_SendGoal_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: goal
  {
    out << "goal: ";
    to_flow_style_yaml(msg.goal, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const PoseGoal_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: goal
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal:\n";
    to_block_style_yaml(msg.goal, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const PoseGoal_SendGoal_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace robot_action

namespace rosidl_generator_traits
{

[[deprecated("use robot_action::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const robot_action::action::PoseGoal_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  robot_action::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use robot_action::action::to_yaml() instead")]]
inline std::string to_yaml(const robot_action::action::PoseGoal_SendGoal_Request & msg)
{
  return robot_action::action::to_yaml(msg);
}

template<>
inline const char * data_type<robot_action::action::PoseGoal_SendGoal_Request>()
{
  return "robot_action::action::PoseGoal_SendGoal_Request";
}

template<>
inline const char * name<robot_action::action::PoseGoal_SendGoal_Request>()
{
  return "robot_action/action/PoseGoal_SendGoal_Request";
}

template<>
struct has_fixed_size<robot_action::action::PoseGoal_SendGoal_Request>
  : std::integral_constant<bool, has_fixed_size<robot_action::action::PoseGoal_Goal>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<robot_action::action::PoseGoal_SendGoal_Request>
  : std::integral_constant<bool, has_bounded_size<robot_action::action::PoseGoal_Goal>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<robot_action::action::PoseGoal_SendGoal_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace robot_action
{

namespace action
{

inline void to_flow_style_yaml(
  const PoseGoal_SendGoal_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: accepted
  {
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << ", ";
  }

  // member: stamp
  {
    out << "stamp: ";
    to_flow_style_yaml(msg.stamp, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const PoseGoal_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: accepted
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << "\n";
  }

  // member: stamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "stamp:\n";
    to_block_style_yaml(msg.stamp, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const PoseGoal_SendGoal_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace robot_action

namespace rosidl_generator_traits
{

[[deprecated("use robot_action::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const robot_action::action::PoseGoal_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  robot_action::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use robot_action::action::to_yaml() instead")]]
inline std::string to_yaml(const robot_action::action::PoseGoal_SendGoal_Response & msg)
{
  return robot_action::action::to_yaml(msg);
}

template<>
inline const char * data_type<robot_action::action::PoseGoal_SendGoal_Response>()
{
  return "robot_action::action::PoseGoal_SendGoal_Response";
}

template<>
inline const char * name<robot_action::action::PoseGoal_SendGoal_Response>()
{
  return "robot_action/action/PoseGoal_SendGoal_Response";
}

template<>
struct has_fixed_size<robot_action::action::PoseGoal_SendGoal_Response>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct has_bounded_size<robot_action::action::PoseGoal_SendGoal_Response>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct is_message<robot_action::action::PoseGoal_SendGoal_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<robot_action::action::PoseGoal_SendGoal>()
{
  return "robot_action::action::PoseGoal_SendGoal";
}

template<>
inline const char * name<robot_action::action::PoseGoal_SendGoal>()
{
  return "robot_action/action/PoseGoal_SendGoal";
}

template<>
struct has_fixed_size<robot_action::action::PoseGoal_SendGoal>
  : std::integral_constant<
    bool,
    has_fixed_size<robot_action::action::PoseGoal_SendGoal_Request>::value &&
    has_fixed_size<robot_action::action::PoseGoal_SendGoal_Response>::value
  >
{
};

template<>
struct has_bounded_size<robot_action::action::PoseGoal_SendGoal>
  : std::integral_constant<
    bool,
    has_bounded_size<robot_action::action::PoseGoal_SendGoal_Request>::value &&
    has_bounded_size<robot_action::action::PoseGoal_SendGoal_Response>::value
  >
{
};

template<>
struct is_service<robot_action::action::PoseGoal_SendGoal>
  : std::true_type
{
};

template<>
struct is_service_request<robot_action::action::PoseGoal_SendGoal_Request>
  : std::true_type
{
};

template<>
struct is_service_response<robot_action::action::PoseGoal_SendGoal_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"

namespace robot_action
{

namespace action
{

inline void to_flow_style_yaml(
  const PoseGoal_GetResult_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const PoseGoal_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const PoseGoal_GetResult_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace robot_action

namespace rosidl_generator_traits
{

[[deprecated("use robot_action::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const robot_action::action::PoseGoal_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  robot_action::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use robot_action::action::to_yaml() instead")]]
inline std::string to_yaml(const robot_action::action::PoseGoal_GetResult_Request & msg)
{
  return robot_action::action::to_yaml(msg);
}

template<>
inline const char * data_type<robot_action::action::PoseGoal_GetResult_Request>()
{
  return "robot_action::action::PoseGoal_GetResult_Request";
}

template<>
inline const char * name<robot_action::action::PoseGoal_GetResult_Request>()
{
  return "robot_action/action/PoseGoal_GetResult_Request";
}

template<>
struct has_fixed_size<robot_action::action::PoseGoal_GetResult_Request>
  : std::integral_constant<bool, has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<robot_action::action::PoseGoal_GetResult_Request>
  : std::integral_constant<bool, has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<robot_action::action::PoseGoal_GetResult_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'result'
// already included above
// #include "robot_action/action/detail/pose_goal__traits.hpp"

namespace robot_action
{

namespace action
{

inline void to_flow_style_yaml(
  const PoseGoal_GetResult_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: status
  {
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << ", ";
  }

  // member: result
  {
    out << "result: ";
    to_flow_style_yaml(msg.result, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const PoseGoal_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << "\n";
  }

  // member: result
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "result:\n";
    to_block_style_yaml(msg.result, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const PoseGoal_GetResult_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace robot_action

namespace rosidl_generator_traits
{

[[deprecated("use robot_action::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const robot_action::action::PoseGoal_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  robot_action::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use robot_action::action::to_yaml() instead")]]
inline std::string to_yaml(const robot_action::action::PoseGoal_GetResult_Response & msg)
{
  return robot_action::action::to_yaml(msg);
}

template<>
inline const char * data_type<robot_action::action::PoseGoal_GetResult_Response>()
{
  return "robot_action::action::PoseGoal_GetResult_Response";
}

template<>
inline const char * name<robot_action::action::PoseGoal_GetResult_Response>()
{
  return "robot_action/action/PoseGoal_GetResult_Response";
}

template<>
struct has_fixed_size<robot_action::action::PoseGoal_GetResult_Response>
  : std::integral_constant<bool, has_fixed_size<robot_action::action::PoseGoal_Result>::value> {};

template<>
struct has_bounded_size<robot_action::action::PoseGoal_GetResult_Response>
  : std::integral_constant<bool, has_bounded_size<robot_action::action::PoseGoal_Result>::value> {};

template<>
struct is_message<robot_action::action::PoseGoal_GetResult_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<robot_action::action::PoseGoal_GetResult>()
{
  return "robot_action::action::PoseGoal_GetResult";
}

template<>
inline const char * name<robot_action::action::PoseGoal_GetResult>()
{
  return "robot_action/action/PoseGoal_GetResult";
}

template<>
struct has_fixed_size<robot_action::action::PoseGoal_GetResult>
  : std::integral_constant<
    bool,
    has_fixed_size<robot_action::action::PoseGoal_GetResult_Request>::value &&
    has_fixed_size<robot_action::action::PoseGoal_GetResult_Response>::value
  >
{
};

template<>
struct has_bounded_size<robot_action::action::PoseGoal_GetResult>
  : std::integral_constant<
    bool,
    has_bounded_size<robot_action::action::PoseGoal_GetResult_Request>::value &&
    has_bounded_size<robot_action::action::PoseGoal_GetResult_Response>::value
  >
{
};

template<>
struct is_service<robot_action::action::PoseGoal_GetResult>
  : std::true_type
{
};

template<>
struct is_service_request<robot_action::action::PoseGoal_GetResult_Request>
  : std::true_type
{
};

template<>
struct is_service_response<robot_action::action::PoseGoal_GetResult_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'feedback'
// already included above
// #include "robot_action/action/detail/pose_goal__traits.hpp"

namespace robot_action
{

namespace action
{

inline void to_flow_style_yaml(
  const PoseGoal_FeedbackMessage & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: feedback
  {
    out << "feedback: ";
    to_flow_style_yaml(msg.feedback, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const PoseGoal_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: feedback
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "feedback:\n";
    to_block_style_yaml(msg.feedback, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const PoseGoal_FeedbackMessage & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace robot_action

namespace rosidl_generator_traits
{

[[deprecated("use robot_action::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const robot_action::action::PoseGoal_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  robot_action::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use robot_action::action::to_yaml() instead")]]
inline std::string to_yaml(const robot_action::action::PoseGoal_FeedbackMessage & msg)
{
  return robot_action::action::to_yaml(msg);
}

template<>
inline const char * data_type<robot_action::action::PoseGoal_FeedbackMessage>()
{
  return "robot_action::action::PoseGoal_FeedbackMessage";
}

template<>
inline const char * name<robot_action::action::PoseGoal_FeedbackMessage>()
{
  return "robot_action/action/PoseGoal_FeedbackMessage";
}

template<>
struct has_fixed_size<robot_action::action::PoseGoal_FeedbackMessage>
  : std::integral_constant<bool, has_fixed_size<robot_action::action::PoseGoal_Feedback>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<robot_action::action::PoseGoal_FeedbackMessage>
  : std::integral_constant<bool, has_bounded_size<robot_action::action::PoseGoal_Feedback>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<robot_action::action::PoseGoal_FeedbackMessage>
  : std::true_type {};

}  // namespace rosidl_generator_traits


namespace rosidl_generator_traits
{

template<>
struct is_action<robot_action::action::PoseGoal>
  : std::true_type
{
};

template<>
struct is_action_goal<robot_action::action::PoseGoal_Goal>
  : std::true_type
{
};

template<>
struct is_action_result<robot_action::action::PoseGoal_Result>
  : std::true_type
{
};

template<>
struct is_action_feedback<robot_action::action::PoseGoal_Feedback>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits


#endif  // ROBOT_ACTION__ACTION__DETAIL__POSE_GOAL__TRAITS_HPP_
