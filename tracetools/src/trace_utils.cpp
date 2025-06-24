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

#define TRACEPOINT_CREATE_PROBES
#define TRACEPOINT_DEFINE

#include <iostream>
#include <mutex>
#include <thread>
#include "tracetools/trace_utils.h"

#define TRACE_MESSAGE_LENGTH 1024

int TraceMarkerFD = -1;

void InitializeTrace()
{
  TraceMarkerFD = open("/sys/kernel/debug/tracing/trace_marker", O_WRONLY);
  if (TraceMarkerFD == -1) {
    TraceMarkerFD = open("/sys/kernel/tracing/trace_marker", O_WRONLY);
      if (TraceMarkerFD == -1) {
        printf("Error opening trace file: %s (%d)", strerror(errno), errno);
        return;
      }
  }
  printf("Tracing initialized successfully.\n");
}

void InitializeTraceOnce() 
{
  static std::once_flag init_flag;
  std::call_once(init_flag, InitializeTrace);
}

void TraceBegin(const char* pName)
{
  char buf[TRACE_MESSAGE_LENGTH];
  int32_t len;

  len = snprintf(buf, TRACE_MESSAGE_LENGTH, "B|%d|%s", getpid(), pName);
  //printf("TraceBegin buf is %s\n", buf);
  write(TraceMarkerFD, buf, len);
}

void TraceEnd()
{
  char c = 'E';
  write(TraceMarkerFD, &c, 1);
}

void TraceAsyncBegin(const char* pName, int32_t cookie)
{
  char buf[TRACE_MESSAGE_LENGTH];
  int32_t len;

  len = snprintf(buf, TRACE_MESSAGE_LENGTH, "S|%d|%s|%" PRId32, getpid(), pName, cookie);
  write(TraceMarkerFD, buf, len);
}

void TraceAsyncEnd(const char* pName, int32_t cookie)
{
  char buf[TRACE_MESSAGE_LENGTH];
  int32_t len;

  len = snprintf(buf, TRACE_MESSAGE_LENGTH, "F|%d|%s|%" PRId32, getpid(), pName, cookie);
  write(TraceMarkerFD, buf, len);
}

void TraceInt(const char* pName, int32_t value)
{
  char buf[TRACE_MESSAGE_LENGTH];
  int32_t len;

  len = snprintf(buf, TRACE_MESSAGE_LENGTH, "C|%d|%s|%" PRId32, getpid(), pName, value);
  write(TraceMarkerFD, buf, len);
}

void TraceInt64(const char* pName, int64_t value)
{
  char buf[TRACE_MESSAGE_LENGTH];
  int32_t len;

  len = snprintf(buf, TRACE_MESSAGE_LENGTH, "C|%d|%s|%" PRId64, getpid(), pName, value);
  write(TraceMarkerFD, buf, len);
}