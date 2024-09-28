// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_interface:srv/ChangeModeDlc.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACE__SRV__DETAIL__CHANGE_MODE_DLC__BUILDER_HPP_
#define CUSTOM_INTERFACE__SRV__DETAIL__CHANGE_MODE_DLC__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_interface/srv/detail/change_mode_dlc__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_interface
{

namespace srv
{

namespace builder
{

class Init_ChangeModeDlc_Request_mode
{
public:
  Init_ChangeModeDlc_Request_mode()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::custom_interface::srv::ChangeModeDlc_Request mode(::custom_interface::srv::ChangeModeDlc_Request::_mode_type arg)
  {
    msg_.mode = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interface::srv::ChangeModeDlc_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interface::srv::ChangeModeDlc_Request>()
{
  return custom_interface::srv::builder::Init_ChangeModeDlc_Request_mode();
}

}  // namespace custom_interface


namespace custom_interface
{

namespace srv
{

namespace builder
{

class Init_ChangeModeDlc_Response_success
{
public:
  Init_ChangeModeDlc_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::custom_interface::srv::ChangeModeDlc_Response success(::custom_interface::srv::ChangeModeDlc_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interface::srv::ChangeModeDlc_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interface::srv::ChangeModeDlc_Response>()
{
  return custom_interface::srv::builder::Init_ChangeModeDlc_Response_success();
}

}  // namespace custom_interface

#endif  // CUSTOM_INTERFACE__SRV__DETAIL__CHANGE_MODE_DLC__BUILDER_HPP_
