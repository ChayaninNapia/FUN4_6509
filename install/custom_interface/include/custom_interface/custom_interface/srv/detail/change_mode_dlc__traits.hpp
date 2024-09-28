// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from custom_interface:srv/ChangeModeDlc.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACE__SRV__DETAIL__CHANGE_MODE_DLC__TRAITS_HPP_
#define CUSTOM_INTERFACE__SRV__DETAIL__CHANGE_MODE_DLC__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "custom_interface/srv/detail/change_mode_dlc__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace custom_interface
{

namespace srv
{

inline void to_flow_style_yaml(
  const ChangeModeDlc_Request & msg,
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
  const ChangeModeDlc_Request & msg,
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

inline std::string to_yaml(const ChangeModeDlc_Request & msg, bool use_flow_style = false)
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

}  // namespace custom_interface

namespace rosidl_generator_traits
{

[[deprecated("use custom_interface::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const custom_interface::srv::ChangeModeDlc_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_interface::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_interface::srv::to_yaml() instead")]]
inline std::string to_yaml(const custom_interface::srv::ChangeModeDlc_Request & msg)
{
  return custom_interface::srv::to_yaml(msg);
}

template<>
inline const char * data_type<custom_interface::srv::ChangeModeDlc_Request>()
{
  return "custom_interface::srv::ChangeModeDlc_Request";
}

template<>
inline const char * name<custom_interface::srv::ChangeModeDlc_Request>()
{
  return "custom_interface/srv/ChangeModeDlc_Request";
}

template<>
struct has_fixed_size<custom_interface::srv::ChangeModeDlc_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<custom_interface::srv::ChangeModeDlc_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<custom_interface::srv::ChangeModeDlc_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace custom_interface
{

namespace srv
{

inline void to_flow_style_yaml(
  const ChangeModeDlc_Response & msg,
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
  const ChangeModeDlc_Response & msg,
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

inline std::string to_yaml(const ChangeModeDlc_Response & msg, bool use_flow_style = false)
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

}  // namespace custom_interface

namespace rosidl_generator_traits
{

[[deprecated("use custom_interface::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const custom_interface::srv::ChangeModeDlc_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_interface::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_interface::srv::to_yaml() instead")]]
inline std::string to_yaml(const custom_interface::srv::ChangeModeDlc_Response & msg)
{
  return custom_interface::srv::to_yaml(msg);
}

template<>
inline const char * data_type<custom_interface::srv::ChangeModeDlc_Response>()
{
  return "custom_interface::srv::ChangeModeDlc_Response";
}

template<>
inline const char * name<custom_interface::srv::ChangeModeDlc_Response>()
{
  return "custom_interface/srv/ChangeModeDlc_Response";
}

template<>
struct has_fixed_size<custom_interface::srv::ChangeModeDlc_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<custom_interface::srv::ChangeModeDlc_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<custom_interface::srv::ChangeModeDlc_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<custom_interface::srv::ChangeModeDlc>()
{
  return "custom_interface::srv::ChangeModeDlc";
}

template<>
inline const char * name<custom_interface::srv::ChangeModeDlc>()
{
  return "custom_interface/srv/ChangeModeDlc";
}

template<>
struct has_fixed_size<custom_interface::srv::ChangeModeDlc>
  : std::integral_constant<
    bool,
    has_fixed_size<custom_interface::srv::ChangeModeDlc_Request>::value &&
    has_fixed_size<custom_interface::srv::ChangeModeDlc_Response>::value
  >
{
};

template<>
struct has_bounded_size<custom_interface::srv::ChangeModeDlc>
  : std::integral_constant<
    bool,
    has_bounded_size<custom_interface::srv::ChangeModeDlc_Request>::value &&
    has_bounded_size<custom_interface::srv::ChangeModeDlc_Response>::value
  >
{
};

template<>
struct is_service<custom_interface::srv::ChangeModeDlc>
  : std::true_type
{
};

template<>
struct is_service_request<custom_interface::srv::ChangeModeDlc_Request>
  : std::true_type
{
};

template<>
struct is_service_response<custom_interface::srv::ChangeModeDlc_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // CUSTOM_INTERFACE__SRV__DETAIL__CHANGE_MODE_DLC__TRAITS_HPP_
