#include "QwtApplication.h"

namespace NSApplication::NSQwtPlotter {

QwtApplication::QwtApplication()
    : MainWindow_(std::make_unique<MainWindow>()),
      AppImpl_(std::make_unique<QwtAppImpl>(MainWindow_.get())) {
}

void QwtApplication::show() {
  MainWindow_->show();
}

} // namespace NSApplication::NSQwtPlotter
