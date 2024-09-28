// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_msg:msg/Qtarget.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSG__MSG__DETAIL__QTARGET__BUILDER_HPP_
#define CUSTOM_MSG__MSG__DETAIL__QTARGET__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_msg/msg/detail/qtarget__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_msg
{

namespace msg
{

namespace builder
{

class Init_Qtarget_current_q
{
public:
  explicit Init_Qtarget_current_q(::custom_msg::msg::Qtarget & msg)
  : msg_(msg)
  {}
  ::custom_msg::msg::Qtarget current_q(::custom_msg::msg::Qtarget::_current_q_type arg)
  {
    msg_.current_q = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_msg::msg::Qtarget msg_;
};

class Init_Qtarget_target_q
{
public:
  Init_Qtarget_target_q()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Qtarget_current_q target_q(::custom_msg::msg::Qtarget::_target_q_type arg)
  {
    msg_.target_q = std::move(arg);
    return Init_Qtarget_current_q(msg_);
  }

private:
  ::custom_msg::msg::Qtarget msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_msg::msg::Qtarget>()
{
  return custom_msg::msg::builder::Init_Qtarget_target_q();
}

}  // namespace custom_msg

#endif  // CUSTOM_MSG__MSG__DETAIL__QTARGET__BUILDER_HPP_
