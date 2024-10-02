// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from robot_action:srv/ChangeMode.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_ACTION__SRV__DETAIL__CHANGE_MODE__TRAITS_HPP_
#define ROBOT_ACTION__SRV__DETAIL__CHANGE_MODE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "robot_action/srv/detail/change_mode__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace robot_action
{

namespace srv
{

inline void to_flow_style_yaml(
  const ChangeMode_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: mode
  {
    out << "mode: ";
    rosidl_generator_traits::value_to_yaml(msg.mode, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ChangeMode_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mode: ";
    rosidl_generator_traits::value_to_yaml(msg.mode, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ChangeMode_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace robot_action

namespace rosidl_generator_traits
{

[[deprecated("use robot_action::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const robot_action::srv::ChangeMode_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  robot_action::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use robot_action::srv::to_yaml() instead")]]
inline std::string to_yaml(const robot_action::srv::ChangeMode_Request & msg)
{
  return robot_action::srv::to_yaml(msg);
}

template<>
inline const char * data_type<robot_action::srv::ChangeMode_Request>()
{
  return "robot_action::srv::ChangeMode_Request";
}

template<>
inline const char * name<robot_action::srv::ChangeMode_Request>()
{
  return "robot_action/srv/ChangeMode_Request";
}

template<>
struct has_fixed_size<robot_action::srv::ChangeMode_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<robot_action::srv::ChangeMode_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<robot_action::srv::ChangeMode_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace robot_action
{

namespace srv
{

inline void to_flow_style_yaml(
  const ChangeMode_Response & msg,
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
  const ChangeMode_Response & msg,
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

inline std::string to_yaml(const ChangeMode_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace robot_action

namespace rosidl_generator_traits
{

[[deprecated("use robot_action::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const robot_action::srv::ChangeMode_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  robot_action::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use robot_action::srv::to_yaml() instead")]]
inline std::string to_yaml(const robot_action::srv::ChangeMode_Response & msg)
{
  return robot_action::srv::to_yaml(msg);
}

template<>
inline const char * data_type<robot_action::srv::ChangeMode_Response>()
{
  return "robot_action::srv::ChangeMode_Response";
}

template<>
inline const char * name<robot_action::srv::ChangeMode_Response>()
{
  return "robot_action/srv/ChangeMode_Response";
}

template<>
struct has_fixed_size<robot_action::srv::ChangeMode_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<robot_action::srv::ChangeMode_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<robot_action::srv::ChangeMode_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<robot_action::srv::ChangeMode>()
{
  return "robot_action::srv::ChangeMode";
}

template<>
inline const char * name<robot_action::srv::ChangeMode>()
{
  return "robot_action/srv/ChangeMode";
}

template<>
struct has_fixed_size<robot_action::srv::ChangeMode>
  : std::integral_constant<
    bool,
    has_fixed_size<robot_action::srv::ChangeMode_Request>::value &&
    has_fixed_size<robot_action::srv::ChangeMode_Response>::value
  >
{
};

template<>
struct has_bounded_size<robot_action::srv::ChangeMode>
  : std::integral_constant<
    bool,
    has_bounded_size<robot_action::srv::ChangeMode_Request>::value &&
    has_bounded_size<robot_action::srv::ChangeMode_Response>::value
  >
{
};

template<>
struct is_service<robot_action::srv::ChangeMode>
  : std::true_type
{
};

template<>
struct is_service_request<robot_action::srv::ChangeMode_Request>
  : std::true_type
{
};

template<>
struct is_service_response<robot_action::srv::ChangeMode_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // ROBOT_ACTION__SRV__DETAIL__CHANGE_MODE__TRAITS_HPP_
