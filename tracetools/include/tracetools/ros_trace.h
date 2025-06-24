// Copyright 2025 qualcomm Technologies, Inc.
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
#undef ROS_TRACE_H_
#ifndef ROS_TRACE_H_
#define ROS_TRACE_H_

#include <stdint.h>
#include <stdbool.h>
#include <cstdio>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <cstring>     // for strerror()
#include <cerrno>      // for errno
#include <cinttypes>   // for PRId32


#include "tracetools/tracetools.h"
#include "tracetools/trace_utils.h"

#ifdef __cplusplus
extern "C"
{
#endif

#ifdef TRACETOOLS_PERFETTO_ENABLED

static const uint32_t MAX_TRACE_STRING_LENGTH = 512;

#define ROS_TRACE_ENABLE()                                                                                \
{                                                                                                         \
    InitializeTraceOnce();                                                                                \
}                                                                                                           \

#define ROS_TRACE_SYNC_BEGIN_F(...)                                                                         \
{                                                                                                            \
    char TraceNameRandomString[MAX_TRACE_STRING_LENGTH];                                                     \
    snprintf(TraceNameRandomString, sizeof(TraceNameRandomString), ##__VA_ARGS__);                              \
    TraceBegin(TraceNameRandomString);                                                                         \
}

#define ROS_TRACE_ASYNC_BEGIN_F(id, ...)                                                                         \
{                                                                                                                \
    char TraceNameRandomString[MAX_TRACE_STRING_LENGTH];                                                          \
    snprintf(TraceNameRandomString, sizeof(TraceNameRandomString), ##__VA_ARGS__);                                \
    TraceAsyncBegin(TraceNameRandomString, static_cast<uint32_t>(id));                                             \
}

#define ROS_TRACE_ASYNC_END_F(id, ...)                                                                               \
{                                                                                                                   \
    char TraceNameRandomString[MAX_TRACE_STRING_LENGTH];                                                            \
    snprintf(TraceNameRandomString, sizeof(TraceNameRandomString), ##__VA_ARGS__);                                  \
    TraceAsyncEnd(TraceNameRandomString, static_cast<uint32_t>(id));                                          \
}

#define ROS_TRACE_INT32_F(value, ...)                                                                            \
{                                                                                                                \
    char TraceNameRandomString[MAX_TRACE_STRING_LENGTH];                                                        \
    snprintf(TraceNameRandomString, sizeof(TraceNameRandomString), ##__VA_ARGS__);                              \
    TraceInt(TraceNameRandomString, value);                                                                      \
}

#define ROS_TRACE_MESSAGE_F(...)                                                                                \
{                                                                                                                \
    char TraceNameRandomString[MAX_TRACE_STRING_LENGTH];                                                      \
    snprintf(TraceNameRandomString, sizeof(TraceNameRandomString), ##__VA_ARGS__);                              \
    TraceBegin(TraceNameRandomString);                                                                         \
    TraceEnd();                                                                                               \
}

#define ROS_TRACE_SYNC_BEGIN(string)                                                                                \
{                                                                                                                \
    TraceBegin(string);                                                                                        \
}                                                                                                

#define ROS_TRACE_SYNC_END()                                                                                \
{                                                                                                                \
    TraceEnd();                                                                                           \
}

#define ROS_TRACE_MESSAGE(string)                                                                                \
{                                                                                                                \
    TraceBegin(string);                                                                                          \
    TraceEnd();                                                                                               \
}

#else

#define ROS_TRACE_SYNC_BEGIN_F(...)
#define ROS_TRACE_ASYNC_BEGIN_F(...)
#define ROS_TRACE_ASYNC_END_F(...)
#define ROS_TRACE_INT32_F(...)
#define ROS_TRACE_MESSAGE_F(...)
#define ROS_TRACE_SYNC_BEGIN(...)
#define ROS_TRACE_SYNC_END(...)
#define ROS_TRACE_MESSAGE(...)

#endif  // TRACETOOLS_PERFETTO_ENABLED

#ifdef __cplusplus
}
#endif

#endif  //ROS_TRACE_H_