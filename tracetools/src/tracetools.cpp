// Copyright 2019 Robert Bosch GmbH
// Copyright 2020 Christophe Bedard
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "tracetools/tracetools.h"

#ifndef TRACETOOLS_DISABLED

#ifdef TRACETOOLS_PERFETTO_ENABLED
# include "tracetools/ros_trace.h"
#endif

bool ros_trace_compile_status()
{
#ifdef TRACETOOLS_PERFETTO_ENABLED
  return true;
#else
  return false;
#endif
}

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
#else
# pragma warning(push)
# pragma warning(disable: 4100)
#endif

void TRACEPOINT(
  rcl_init,
  const void * context_handle)
{
#ifdef TRACETOOLS_PERFETTO_ENABLED
  ROS_TRACE_ENABLE();
  ROS_TRACE_MESSAGE_F(
    "ros2 rcl_init context_handle: %p",
    context_handle);
#endif
}

void TRACEPOINT(
  rcl_node_init,
  const void * node_handle,
  const void * rmw_handle,
  const char * node_name,
  const char * node_namespace)
{
#ifdef TRACETOOLS_PERFETTO_ENABLED
  ROS_TRACE_ENABLE();
  ROS_TRACE_MESSAGE_F(
    "ros2 rcl_node_init node_handle: %p, rmw_handle: %p, node_name: %s, node_namespace: %s",
    node_handle,
    rmw_handle,
    node_name,
    node_namespace);
#endif
}

void TRACEPOINT(
  rmw_publisher_init,
  const void * rmw_publisher_handle,
  const uint8_t * gid)
{
#ifdef TRACETOOLS_PERFETTO_ENABLED
  ROS_TRACE_ENABLE();
  ROS_TRACE_MESSAGE_F(
    "ros2 rmw_publisher_init rmw_publisher_handle: %p, gid: %" PRIu8,
    rmw_publisher_handle,
    gid);
#endif
}

void TRACEPOINT(
  rcl_publisher_init,
  const void * publisher_handle,
  const void * node_handle,
  const void * rmw_publisher_handle,
  const char * topic_name,
  const size_t queue_depth)
{
#ifdef TRACETOOLS_PERFETTO_ENABLED
  ROS_TRACE_ENABLE();
  ROS_TRACE_MESSAGE_F(
    "ros2 rcl_publisher_init publisher_handle: %p, node_handle: %p,  rmw_publisher_handle: %p, topic_name: %s, queue_depth: %zu", 
    publisher_handle,
    node_handle,
    rmw_publisher_handle,
    topic_name,
    queue_depth);
#endif
}

void TRACEPOINT(
  rclcpp_publish,
  const void * publisher_handle,
  const void * message)
{
#ifdef TRACETOOLS_PERFETTO_ENABLED
  ROS_TRACE_ENABLE();
  ROS_TRACE_MESSAGE_F(
    "ros2 rclcpp_publish publisher_handle: %p, message: %p",
    publisher_handle,
    message);
#endif
}

void TRACEPOINT(
  rcl_publish,
  const void * publisher_handle,
  const void * message)
{
#ifdef TRACETOOLS_PERFETTO_ENABLED
  ROS_TRACE_ENABLE();
  ROS_TRACE_MESSAGE_F(
    "ros2 rcl_publish publisher_handle: %p, message: %p",
    publisher_handle,
    message);
#endif
}

void TRACEPOINT(
  rmw_publish,
  const void * message)
{
#ifdef TRACETOOLS_PERFETTO_ENABLED
  ROS_TRACE_ENABLE();
  ROS_TRACE_MESSAGE_F(
    "ros2 rmw_publish message: %p",
    message);
#endif
}

void TRACEPOINT(
  rmw_subscription_init,
  const void * rmw_subscription_handle,
  const uint8_t * gid)
{
#ifdef TRACETOOLS_PERFETTO_ENABLED
  ROS_TRACE_ENABLE();
  ROS_TRACE_MESSAGE_F(
    "ros2 rmw_subscription_init rmw_subscription_handle: %p, gid: %" PRIu8,
    rmw_subscription_handle,
    gid);
#endif
}

void TRACEPOINT(
  rcl_subscription_init,
  const void * subscription_handle,
  const void * node_handle,
  const void * rmw_subscription_handle,
  const char * topic_name,
  const size_t queue_depth)
{
#ifdef TRACETOOLS_PERFETTO_ENABLED
  ROS_TRACE_ENABLE();
  ROS_TRACE_MESSAGE_F(
    "ros2 rcl_subscription_init subscription_handle: %p, node_handle: %p, rmw_subscription_handle: %p, topic_name: %s, queue_depth: %zu",
    subscription_handle,
    node_handle,
    rmw_subscription_handle,
    topic_name,
    queue_depth);
#endif
}

void TRACEPOINT(
  rclcpp_subscription_init,
  const void * subscription_handle,
  const void * subscription)
{
#ifdef TRACETOOLS_PERFETTO_ENABLED
  ROS_TRACE_ENABLE();
  ROS_TRACE_MESSAGE_F(
    "ros2 rclcpp_subscription_init subscription_handle: %p, subscription: %p", 
    subscription_handle,
    subscription);
#endif
}

void TRACEPOINT(
  rclcpp_subscription_callback_added,
  const void * subscription,
  const void * callback)
{
#ifdef TRACETOOLS_PERFETTO_ENABLED
  ROS_TRACE_ENABLE();
  ROS_TRACE_MESSAGE_F(
    "ros2 rclcpp_subscription_callback_added subscription: %p, callback: %p",
    subscription,
    callback);
#endif
}

void TRACEPOINT(
  rmw_take,
  const void * rmw_subscription_handle,
  const void * message,
  int64_t source_timestamp,
  const bool taken)
{
#ifdef TRACETOOLS_PERFETTO_ENABLED
  ROS_TRACE_ENABLE();
  ROS_TRACE_MESSAGE_F(
    "ros2 rmw_take rmw_subscription_handle: %p, message: %p, source_timestamp: %ld, taken: %d",
    rmw_subscription_handle,
    message,
    source_timestamp,
    taken);
#endif
}

void TRACEPOINT(
  rcl_take,
  const void * message)
{
#ifdef TRACETOOLS_PERFETTO_ENABLED
  ROS_TRACE_ENABLE();
  ROS_TRACE_MESSAGE_F(
    "ros2 rcl_take message: %p",
    message);
#endif
}

void TRACEPOINT(
  rclcpp_take,
  const void * message)
{
#ifdef TRACETOOLS_PERFETTO_ENABLED
  ROS_TRACE_ENABLE();
  ROS_TRACE_MESSAGE_F(
    "ros2 rclcpp_take message: %p",
    message);
#endif
}

void TRACEPOINT(
  rcl_service_init,
  const void * service_handle,
  const void * node_handle,
  const void * rmw_service_handle,
  const char * service_name)
{
#ifdef TRACETOOLS_PERFETTO_ENABLED
  ROS_TRACE_ENABLE();
  ROS_TRACE_MESSAGE_F(
    "ros2 rcl_service_init service_handle: %p, node_handle: %p, rmw_service_handle: %p, service_name: %s",
    service_handle,
    node_handle,
    rmw_service_handle,
    service_name);
#endif
}

void TRACEPOINT(
  rclcpp_service_callback_added,
  const void * service_handle,
  const void * callback)
{
#ifdef TRACETOOLS_PERFETTO_ENABLED
  ROS_TRACE_ENABLE();
  ROS_TRACE_MESSAGE_F(
    "ros2 rclcpp_service_callback_added service_handle: %p, callback: %p",
    service_handle,
    callback);
#endif
}

void TRACEPOINT(
  rcl_client_init,
  const void * client_handle,
  const void * node_handle,
  const void * rmw_client_handle,
  const char * service_name)
{
#ifdef TRACETOOLS_PERFETTO_ENABLED
  ROS_TRACE_ENABLE();
  ROS_TRACE_MESSAGE_F(
    "ros2 rcl_client_init client_handle: %p, node_handle: %p, rmw_client_handle: %p, service_name: %s",
    client_handle,
    node_handle,
    rmw_client_handle,
    service_name);
#endif
}

void TRACEPOINT(
  rcl_timer_init,
  const void * timer_handle,
  int64_t period)
{
#ifdef TRACETOOLS_PERFETTO_ENABLED
  ROS_TRACE_ENABLE();
  ROS_TRACE_MESSAGE_F(
    "ros2 rcl_timer_init timer_handle: %p, period: %ld",
    timer_handle,
    period);
#endif
}

void TRACEPOINT(
  rclcpp_timer_callback_added,
  const void * timer_handle,
  const void * callback)
{
#ifdef TRACETOOLS_PERFETTO_ENABLED
  ROS_TRACE_ENABLE();
  ROS_TRACE_MESSAGE_F(
    "ros2 rclcpp_timer_callback_added timer_handle: %p, callback: %p",
    timer_handle,
    callback);
#endif
}

void TRACEPOINT(
  rclcpp_timer_link_node,
  const void * timer_handle,
  const void * node_handle)
{
#ifdef TRACETOOLS_PERFETTO_ENABLED
  ROS_TRACE_ENABLE();
  ROS_TRACE_MESSAGE_F(
    "ros2 rclcpp_timer_link_node timer_handle: %p, node_handle: %p",
    timer_handle,
    node_handle);
#endif
}

void TRACEPOINT(
  rclcpp_callback_register,
  const void * callback,
  const char * function_symbol)
{
#ifdef TRACETOOLS_PERFETTO_ENABLED
  ROS_TRACE_ENABLE();
  ROS_TRACE_MESSAGE_F(
    "ros2 rclcpp_callback_register callback: %p, function_symbol: %s",
    callback,
    function_symbol);
#endif
}

void TRACEPOINT(
  callback_start,
  const void * callback,
  const bool is_intra_process)
{
#ifdef TRACETOOLS_PERFETTO_ENABLED
  ROS_TRACE_ENABLE();
  ROS_TRACE_ASYNC_BEGIN_F(
    0,
    "ros2 callback_start callback: %p, is_intra_process: %d",
    callback,
    is_intra_process);
#endif
}

void TRACEPOINT(
  callback_end,
  const void * callback)
{
#ifdef TRACETOOLS_PERFETTO_ENABLED
  ROS_TRACE_ENABLE();
  ROS_TRACE_ASYNC_END_F(
    0,
    "ros2 callback_end callback: %p",
    callback);
#endif
}

void TRACEPOINT(
  rcl_lifecycle_state_machine_init,
  const void * node_handle,
  const void * state_machine)
{
#ifdef TRACETOOLS_PERFETTO_ENABLED
  ROS_TRACE_ENABLE();
  ROS_TRACE_MESSAGE_F(
    "ros2 rcl_lifecycle_state_machine_init node_handle: %p, state_machine: %p",
    node_handle,
    state_machine);
#endif
}

void TRACEPOINT(
  rcl_lifecycle_transition,
  const void * state_machine,
  const char * start_label,
  const char * goal_label)
{
#ifdef TRACETOOLS_PERFETTO_ENABLED
  ROS_TRACE_ENABLE();
  ROS_TRACE_MESSAGE_F(
    "ros2 rcl_lifecycle_transition state_machine: %p, start_label: %s, goal_label: %s",
    state_machine,
    start_label,
    goal_label);
#endif
}

void TRACEPOINT(
  rclcpp_executor_get_next_ready)
{
#ifdef TRACETOOLS_PERFETTO_ENABLED
  ROS_TRACE_ENABLE();
  ROS_TRACE_MESSAGE_F(
    "ros2 rclcpp_executor_get_next_ready");
#endif
}

void TRACEPOINT(
  rclcpp_executor_wait_for_work,
  const int64_t timeout)
{
#ifdef TRACETOOLS_PERFETTO_ENABLED
  ROS_TRACE_ENABLE();
  ROS_TRACE_MESSAGE_F(
    "ros2 rclcpp_executor_wait_for_work timeout: %ld",
    timeout);
#endif
}

void TRACEPOINT(
  rclcpp_executor_execute,
  const void * handle)
{
#ifdef TRACETOOLS_PERFETTO_ENABLED
  ROS_TRACE_ENABLE();
  ROS_TRACE_MESSAGE_F(
    "ros2 rclcpp_executor_execute handle: %p",
    handle);
#endif
}

#ifndef _WIN32
# pragma GCC diagnostic pop
#else
# pragma warning(pop)
#endif

#endif  // TRACETOOLS_DISABLED
