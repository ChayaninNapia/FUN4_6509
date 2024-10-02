// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from robot_action:srv/ChangeMode.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_ACTION__SRV__DETAIL__CHANGE_MODE__BUILDER_HPP_
#define ROBOT_ACTION__SRV__DETAIL__CHANGE_MODE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "robot_action/srv/detail/change_mode__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace robot_action
{

namespace srv
{

namespace builder
{

class Init_ChangeMode_Request_mode
{
public:
  Init_ChangeMode_Request_mode()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::robot_action::srv::ChangeMode_Request mode(::robot_action::srv::ChangeMode_Request::_mode_type arg)
  {
    msg_.mode = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_action::srv::ChangeMode_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_action::srv::ChangeMode_Request>()
{
  return robot_action::srv::builder::Init_ChangeMode_Request_mode();
}

}  // namespace robot_action


namespace robot_action
{

namespace srv
{

namespace builder
{

class Init_ChangeMode_Response_success
{
public:
  Init_ChangeMode_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::robot_action::srv::ChangeMode_Response success(::robot_action::srv::ChangeMode_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_action::srv::ChangeMode_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_action::srv::ChangeMode_Response>()
{
  return robot_action::srv::builder::Init_ChangeMode_Response_success();
}

}  // namespace robot_action

#endif  // ROBOT_ACTION__SRV__DETAIL__CHANGE_MODE__BUILDER_HPP_
