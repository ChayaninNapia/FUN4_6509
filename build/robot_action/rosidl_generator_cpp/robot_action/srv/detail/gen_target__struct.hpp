// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from robot_action:srv/GenTarget.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_ACTION__SRV__DETAIL__GEN_TARGET__STRUCT_HPP_
#define ROBOT_ACTION__SRV__DETAIL__GEN_TARGET__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__robot_action__srv__GenTarget_Request __attribute__((deprecated))
#else
# define DEPRECATED__robot_action__srv__GenTarget_Request __declspec(deprecated)
#endif

namespace robot_action
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GenTarget_Request_
{
  using Type = GenTarget_Request_<ContainerAllocator>;

  explicit GenTarget_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->trigger = false;
    }
  }

  explicit GenTarget_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->trigger = false;
    }
  }

  // field types and members
  using _trigger_type =
    bool;
  _trigger_type trigger;

  // setters for named parameter idiom
  Type & set__trigger(
    const bool & _arg)
  {
    this->trigger = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robot_action::srv::GenTarget_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const robot_action::srv::GenTarget_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robot_action::srv::GenTarget_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robot_action::srv::GenTarget_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robot_action::srv::GenTarget_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robot_action::srv::GenTarget_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robot_action::srv::GenTarget_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robot_action::srv::GenTarget_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robot_action::srv::GenTarget_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robot_action::srv::GenTarget_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robot_action__srv__GenTarget_Request
    std::shared_ptr<robot_action::srv::GenTarget_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robot_action__srv__GenTarget_Request
    std::shared_ptr<robot_action::srv::GenTarget_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GenTarget_Request_ & other) const
  {
    if (this->trigger != other.trigger) {
      return false;
    }
    return true;
  }
  bool operator!=(const GenTarget_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GenTarget_Request_

// alias to use template instance with default allocator
using GenTarget_Request =
  robot_action::srv::GenTarget_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace robot_action


// Include directives for member types
// Member 'taskspace'
#include "geometry_msgs/msg/detail/pose_stamped__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__robot_action__srv__GenTarget_Response __attribute__((deprecated))
#else
# define DEPRECATED__robot_action__srv__GenTarget_Response __declspec(deprecated)
#endif

namespace robot_action
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GenTarget_Response_
{
  using Type = GenTarget_Response_<ContainerAllocator>;

  explicit GenTarget_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : taskspace(_init)
  {
    (void)_init;
  }

  explicit GenTarget_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : taskspace(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _taskspace_type =
    geometry_msgs::msg::PoseStamped_<ContainerAllocator>;
  _taskspace_type taskspace;

  // setters for named parameter idiom
  Type & set__taskspace(
    const geometry_msgs::msg::PoseStamped_<ContainerAllocator> & _arg)
  {
    this->taskspace = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robot_action::srv::GenTarget_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const robot_action::srv::GenTarget_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robot_action::srv::GenTarget_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robot_action::srv::GenTarget_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robot_action::srv::GenTarget_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robot_action::srv::GenTarget_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robot_action::srv::GenTarget_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robot_action::srv::GenTarget_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robot_action::srv::GenTarget_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robot_action::srv::GenTarget_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robot_action__srv__GenTarget_Response
    std::shared_ptr<robot_action::srv::GenTarget_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robot_action__srv__GenTarget_Response
    std::shared_ptr<robot_action::srv::GenTarget_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GenTarget_Response_ & other) const
  {
    if (this->taskspace != other.taskspace) {
      return false;
    }
    return true;
  }
  bool operator!=(const GenTarget_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GenTarget_Response_

// alias to use template instance with default allocator
using GenTarget_Response =
  robot_action::srv::GenTarget_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace robot_action

namespace robot_action
{

namespace srv
{

struct GenTarget
{
  using Request = robot_action::srv::GenTarget_Request;
  using Response = robot_action::srv::GenTarget_Response;
};

}  // namespace srv

}  // namespace robot_action

#endif  // ROBOT_ACTION__SRV__DETAIL__GEN_TARGET__STRUCT_HPP_
