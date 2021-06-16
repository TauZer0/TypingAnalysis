#include "Profiler.h"

#include <iostream>

namespace NSApplication::NSSupport {

LogDuration::LogDuration(const std::string& msg)
    : message(msg + ": "), start(std::chrono::steady_clock::now()) {
}

LogDuration::~LogDuration() {
  auto finish = std::chrono::steady_clock::now();
  auto dur = finish - start;
  std::cerr
      << message
      << std::chrono::duration_cast<std::chrono::microseconds>(dur).count()
      << " \u03BCs\n";
}

} // namespace NSApplication::NSSupport
