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
#undef TRACE_UTILS_H_
#ifndef TRACE_UTILS_H_
#define TRACE_UTILS_H_

#include <stdint.h>
#include <stdbool.h>
#include <cstdio>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <cstring>     // for strerror()
#include <cerrno>      // for errno
#include <cinttypes>   // for PRId32


#ifdef __cplusplus
extern "C"
{
#endif

static const uint32_t MaxTraceStringLength    = 512;

void InitializeTrace();
void InitializeTraceOnce();

void TraceBegin(const char* pName);
void TraceEnd();

void TraceAsyncBegin(const char* pName, int32_t cookie);
void TraceAsyncEnd(const char* pName, int32_t cookie);

void TraceInt(const char* pName, int32_t value);
void TraceInt64(const char* pName, int64_t value);

#ifdef __cplusplus
}
#endif

#endif  //TRACE_UTILS_H_
