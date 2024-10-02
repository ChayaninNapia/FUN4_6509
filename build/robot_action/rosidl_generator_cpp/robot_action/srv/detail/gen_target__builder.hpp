// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from robot_action:srv/GenTarget.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_ACTION__SRV__DETAIL__GEN_TARGET__BUILDER_HPP_
#define ROBOT_ACTION__SRV__DETAIL__GEN_TARGET__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "robot_action/srv/detail/gen_target__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace robot_action
{

namespace srv
{

namespace builder
{

class Init_GenTarget_Request_trigger
{
public:
  Init_GenTarget_Request_trigger()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::robot_action::srv::GenTarget_Request trigger(::robot_action::srv::GenTarget_Request::_trigger_type arg)
  {
    msg_.trigger = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_action::srv::GenTarget_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_action::srv::GenTarget_Request>()
{
  return robot_action::srv::builder::Init_GenTarget_Request_trigger();
}

}  // namespace robot_action


namespace robot_action
{

namespace srv
{

namespace builder
{

class Init_GenTarget_Response_taskspace
{
public:
  Init_GenTarget_Response_taskspace()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::robot_action::srv::GenTarget_Response taskspace(::robot_action::srv::GenTarget_Response::_taskspace_type arg)
  {
    msg_.taskspace = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_action::srv::GenTarget_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_action::srv::GenTarget_Response>()
{
  return robot_action::srv::builder::Init_GenTarget_Response_taskspace();
}

}  // namespace robot_action

#endif  // ROBOT_ACTION__SRV__DETAIL__GEN_TARGET__BUILDER_HPP_
