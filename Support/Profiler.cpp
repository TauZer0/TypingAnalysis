#include "Profiler.h"

#include <QDebug>

namespace NSApplication {

namespace NSSupport {

LogDuration::LogDuration(const std::string& message)
    : Message_(message + ": "), Start_(std::chrono::steady_clock::now()) {
}

LogDuration::~LogDuration() {
  auto finish = std::chrono::steady_clock::now();
  auto duration = finish - Start_;
  qDebug()
      << Message_.data()
      << std::chrono::duration_cast<std::chrono::microseconds>(duration).count()
      << "\u03BCs\n";
}

} // namespace NSSupport

} // namespace NSApplication
