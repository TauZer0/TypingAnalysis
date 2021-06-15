#include "QwtApplication.h"

namespace NSApplication::NSQwtPlotter {

QwtApplication::QwtApplication()
    : main_window_(std::make_unique<MainWindow>()),
      app_impl_(std::make_unique<AppImpl>(main_window_->getQtResources())) {
}

void QwtApplication::show() {
  main_window_->show();
}

} // namespace NSApplication::NSQwtPlotter
