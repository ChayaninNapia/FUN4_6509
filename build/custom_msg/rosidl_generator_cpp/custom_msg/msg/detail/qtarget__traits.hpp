// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from custom_msg:msg/Qtarget.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSG__MSG__DETAIL__QTARGET__TRAITS_HPP_
#define CUSTOM_MSG__MSG__DETAIL__QTARGET__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "custom_msg/msg/detail/qtarget__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace custom_msg
{

namespace msg
{

inline void to_flow_style_yaml(
  const Qtarget & msg,
  std::ostream & out)
{
  out << "{";
  // member: target_q
  {
    if (msg.target_q.size() == 0) {
      out << "target_q: []";
    } else {
      out << "target_q: [";
      size_t pending_items = msg.target_q.size();
      for (auto item : msg.target_q) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

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
  const Qtarget & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: target_q
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.target_q.size() == 0) {
      out << "target_q: []\n";
    } else {
      out << "target_q:\n";
      for (auto item : msg.target_q) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

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

inline std::string to_yaml(const Qtarget & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace custom_msg

namespace rosidl_generator_traits
{

[[deprecated("use custom_msg::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const custom_msg::msg::Qtarget & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_msg::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_msg::msg::to_yaml() instead")]]
inline std::string to_yaml(const custom_msg::msg::Qtarget & msg)
{
  return custom_msg::msg::to_yaml(msg);
}

template<>
inline const char * data_type<custom_msg::msg::Qtarget>()
{
  return "custom_msg::msg::Qtarget";
}

template<>
inline const char * name<custom_msg::msg::Qtarget>()
{
  return "custom_msg/msg/Qtarget";
}

template<>
struct has_fixed_size<custom_msg::msg::Qtarget>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<custom_msg::msg::Qtarget>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<custom_msg::msg::Qtarget>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CUSTOM_MSG__MSG__DETAIL__QTARGET__TRAITS_HPP_
