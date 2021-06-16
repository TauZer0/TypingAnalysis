#include "Support/Suppressor.h"

namespace NSApplication::NSSupport {

void Suppressor::activate() {
  IsActive_ = true;
}

void Suppressor::deactivate() {
  IsActive_ = false;
}

bool Suppressor::isActive() const {
  return IsActive_;
}

// BasicLockable
void Suppressor::lock() {
  activate();
}

void Suppressor::unlock() {
  deactivate();
}

} // namespace NSApplication::NSSupport
