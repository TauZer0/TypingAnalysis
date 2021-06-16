#include "QwtApplication.h"

namespace NSApplication::NSQwtPlotter {

QwtApplication::QwtApplication()
    : MainWindow_(std::make_unique<MainWindow>()),
      AppImpl_(std::make_unique<AppImpl>(MainWindow_->getQtResources())) {
}

void QwtApplication::show() {
  MainWindow_->show();
}

} // namespace NSApplication::NSQwtPlotter
