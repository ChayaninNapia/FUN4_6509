// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_interface:srv/Mode3Control.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACE__SRV__DETAIL__MODE3_CONTROL__BUILDER_HPP_
#define CUSTOM_INTERFACE__SRV__DETAIL__MODE3_CONTROL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_interface/srv/detail/mode3_control__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_interface
{

namespace srv
{

namespace builder
{

class Init_Mode3Control_Request_target_joint_positions
{
public:
  Init_Mode3Control_Request_target_joint_positions()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::custom_interface::srv::Mode3Control_Request target_joint_positions(::custom_interface::srv::Mode3Control_Request::_target_joint_positions_type arg)
  {
    msg_.target_joint_positions = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interface::srv::Mode3Control_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interface::srv::Mode3Control_Request>()
{
  return custom_interface::srv::builder::Init_Mode3Control_Request_target_joint_positions();
}

}  // namespace custom_interface


namespace custom_interface
{

namespace srv
{

namespace builder
{

class Init_Mode3Control_Response_message
{
public:
  explicit Init_Mode3Control_Response_message(::custom_interface::srv::Mode3Control_Response & msg)
  : msg_(msg)
  {}
  ::custom_interface::srv::Mode3Control_Response message(::custom_interface::srv::Mode3Control_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interface::srv::Mode3Control_Response msg_;
};

class Init_Mode3Control_Response_success
{
public:
  Init_Mode3Control_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Mode3Control_Response_message success(::custom_interface::srv::Mode3Control_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_Mode3Control_Response_message(msg_);
  }

private:
  ::custom_interface::srv::Mode3Control_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interface::srv::Mode3Control_Response>()
{
  return custom_interface::srv::builder::Init_Mode3Control_Response_success();
}

}  // namespace custom_interface

#endif  // CUSTOM_INTERFACE__SRV__DETAIL__MODE3_CONTROL__BUILDER_HPP_
