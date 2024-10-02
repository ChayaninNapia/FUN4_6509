// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from robot_action:srv/SetTaskspace.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_ACTION__SRV__DETAIL__SET_TASKSPACE__BUILDER_HPP_
#define ROBOT_ACTION__SRV__DETAIL__SET_TASKSPACE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "robot_action/srv/detail/set_taskspace__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace robot_action
{

namespace srv
{

namespace builder
{

class Init_SetTaskspace_Request_z
{
public:
  explicit Init_SetTaskspace_Request_z(::robot_action::srv::SetTaskspace_Request & msg)
  : msg_(msg)
  {}
  ::robot_action::srv::SetTaskspace_Request z(::robot_action::srv::SetTaskspace_Request::_z_type arg)
  {
    msg_.z = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_action::srv::SetTaskspace_Request msg_;
};

class Init_SetTaskspace_Request_y
{
public:
  explicit Init_SetTaskspace_Request_y(::robot_action::srv::SetTaskspace_Request & msg)
  : msg_(msg)
  {}
  Init_SetTaskspace_Request_z y(::robot_action::srv::SetTaskspace_Request::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_SetTaskspace_Request_z(msg_);
  }

private:
  ::robot_action::srv::SetTaskspace_Request msg_;
};

class Init_SetTaskspace_Request_x
{
public:
  Init_SetTaskspace_Request_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetTaskspace_Request_y x(::robot_action::srv::SetTaskspace_Request::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_SetTaskspace_Request_y(msg_);
  }

private:
  ::robot_action::srv::SetTaskspace_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_action::srv::SetTaskspace_Request>()
{
  return robot_action::srv::builder::Init_SetTaskspace_Request_x();
}

}  // namespace robot_action


namespace robot_action
{

namespace srv
{

namespace builder
{

class Init_SetTaskspace_Response_success
{
public:
  Init_SetTaskspace_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::robot_action::srv::SetTaskspace_Response success(::robot_action::srv::SetTaskspace_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_action::srv::SetTaskspace_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_action::srv::SetTaskspace_Response>()
{
  return robot_action::srv::builder::Init_SetTaskspace_Response_success();
}

}  // namespace robot_action

#endif  // ROBOT_ACTION__SRV__DETAIL__SET_TASKSPACE__BUILDER_HPP_
