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

#define TRACEPOINT_CREATE_PROBES

#define TRACEPOINT_DEFINE
#include "tracetools/ros_trace.h"
#include "tracetools/tracetools.h"

#include <chrono>
#include <condition_variable>
#include <fstream>
#include <thread>

void DrawPlayer(int player_number) {
  ROS_TRACE_MESSAGE_F("ros2 DrawPlayer player_number: %d", player_number);
  // Sleep to simulate a long computation.
  std::this_thread::sleep_for(std::chrono::milliseconds(500));
}

void DrawGame() {
  for(int i = 0; i < 100; ++i) {
    ROS_TRACE_MESSAGE_F("ros2, DrawGame");
    DrawPlayer(1);
    DrawPlayer(2);
  }
}

int main()
{
#ifdef TRACETOOLS_PERFETTO_ENABLED
    ROS_TRACE_ENABLE();
    printf("Tracing init success for ros2.\n");
    DrawGame();

    printf("Perfetto tracing end.\n");
    return 0;
#else
    printf("Perfetto tracing disabled through configuration.\n");
    return 1;
#endif
}

