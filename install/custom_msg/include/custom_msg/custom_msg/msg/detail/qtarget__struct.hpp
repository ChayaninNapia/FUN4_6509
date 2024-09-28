// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from custom_msg:msg/Qtarget.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSG__MSG__DETAIL__QTARGET__STRUCT_HPP_
#define CUSTOM_MSG__MSG__DETAIL__QTARGET__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__custom_msg__msg__Qtarget __attribute__((deprecated))
#else
# define DEPRECATED__custom_msg__msg__Qtarget __declspec(deprecated)
#endif

namespace custom_msg
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Qtarget_
{
  using Type = Qtarget_<ContainerAllocator>;

  explicit Qtarget_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit Qtarget_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _target_q_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _target_q_type target_q;
  using _current_q_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _current_q_type current_q;

  // setters for named parameter idiom
  Type & set__target_q(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->target_q = _arg;
    return *this;
  }
  Type & set__current_q(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->current_q = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_msg::msg::Qtarget_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_msg::msg::Qtarget_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_msg::msg::Qtarget_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_msg::msg::Qtarget_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_msg::msg::Qtarget_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_msg::msg::Qtarget_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_msg::msg::Qtarget_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_msg::msg::Qtarget_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_msg::msg::Qtarget_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_msg::msg::Qtarget_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_msg__msg__Qtarget
    std::shared_ptr<custom_msg::msg::Qtarget_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_msg__msg__Qtarget
    std::shared_ptr<custom_msg::msg::Qtarget_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Qtarget_ & other) const
  {
    if (this->target_q != other.target_q) {
      return false;
    }
    if (this->current_q != other.current_q) {
      return false;
    }
    return true;
  }
  bool operator!=(const Qtarget_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Qtarget_

// alias to use template instance with default allocator
using Qtarget =
  custom_msg::msg::Qtarget_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace custom_msg

#endif  // CUSTOM_MSG__MSG__DETAIL__QTARGET__STRUCT_HPP_
