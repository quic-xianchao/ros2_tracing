// Copyright 2023 
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
#undef PERFETTO_TRACE_H_
#ifndef PERFETTO_TRACE_H_
#define PERFETTO_TRACE_H_

#undef TRACEPOINT_CATEGORY
#define TRACEPOINT_CATEGORY "ros2"

#undef TRACEPOINT_INCLUDE
#define TRACEPOINT_INCLUDE "tracetools/perfetto_trace.h"

#include "perfetto_sdk/perfetto.h"

PERFETTO_DEFINE_CATEGORIES(
    PERFETTO_CATEGORY(ros2));
    
PERFETTO_TRACK_EVENT_STATIC_STORAGE();

#include <stdint.h>
#include <stdbool.h>

#endif  //PERFETTO_TRACE_H_