// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from robot_action:srv/GenTarget.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "robot_action/srv/detail/gen_target__struct.hpp"
#include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
#include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace robot_action
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _GenTarget_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _GenTarget_Request_type_support_ids_t;

static const _GenTarget_Request_type_support_ids_t _GenTarget_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _GenTarget_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _GenTarget_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _GenTarget_Request_type_support_symbol_names_t _GenTarget_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, robot_action, srv, GenTarget_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, robot_action, srv, GenTarget_Request)),
  }
};

typedef struct _GenTarget_Request_type_support_data_t
{
  void * data[2];
} _GenTarget_Request_type_support_data_t;

static _GenTarget_Request_type_support_data_t _GenTarget_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _GenTarget_Request_message_typesupport_map = {
  2,
  "robot_action",
  &_GenTarget_Request_message_typesupport_ids.typesupport_identifier[0],
  &_GenTarget_Request_message_typesupport_symbol_names.symbol_name[0],
  &_GenTarget_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t GenTarget_Request_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_GenTarget_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace robot_action

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<robot_action::srv::GenTarget_Request>()
{
  return &::robot_action::srv::rosidl_typesupport_cpp::GenTarget_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, robot_action, srv, GenTarget_Request)() {
  return get_message_type_support_handle<robot_action::srv::GenTarget_Request>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "robot_action/srv/detail/gen_target__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace robot_action
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _GenTarget_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _GenTarget_Response_type_support_ids_t;

static const _GenTarget_Response_type_support_ids_t _GenTarget_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _GenTarget_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _GenTarget_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _GenTarget_Response_type_support_symbol_names_t _GenTarget_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, robot_action, srv, GenTarget_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, robot_action, srv, GenTarget_Response)),
  }
};

typedef struct _GenTarget_Response_type_support_data_t
{
  void * data[2];
} _GenTarget_Response_type_support_data_t;

static _GenTarget_Response_type_support_data_t _GenTarget_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _GenTarget_Response_message_typesupport_map = {
  2,
  "robot_action",
  &_GenTarget_Response_message_typesupport_ids.typesupport_identifier[0],
  &_GenTarget_Response_message_typesupport_symbol_names.symbol_name[0],
  &_GenTarget_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t GenTarget_Response_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_GenTarget_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace robot_action

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<robot_action::srv::GenTarget_Response>()
{
  return &::robot_action::srv::rosidl_typesupport_cpp::GenTarget_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, robot_action, srv, GenTarget_Response)() {
  return get_message_type_support_handle<robot_action::srv::GenTarget_Response>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "robot_action/srv/detail/gen_target__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/service_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace robot_action
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _GenTarget_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _GenTarget_type_support_ids_t;

static const _GenTarget_type_support_ids_t _GenTarget_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _GenTarget_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _GenTarget_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _GenTarget_type_support_symbol_names_t _GenTarget_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, robot_action, srv, GenTarget)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, robot_action, srv, GenTarget)),
  }
};

typedef struct _GenTarget_type_support_data_t
{
  void * data[2];
} _GenTarget_type_support_data_t;

static _GenTarget_type_support_data_t _GenTarget_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _GenTarget_service_typesupport_map = {
  2,
  "robot_action",
  &_GenTarget_service_typesupport_ids.typesupport_identifier[0],
  &_GenTarget_service_typesupport_symbol_names.symbol_name[0],
  &_GenTarget_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t GenTarget_service_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_GenTarget_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace robot_action

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<robot_action::srv::GenTarget>()
{
  return &::robot_action::srv::rosidl_typesupport_cpp::GenTarget_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp
