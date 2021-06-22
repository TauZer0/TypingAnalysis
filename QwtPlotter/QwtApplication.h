#ifndef QWTAPPLICATION_H
#define QWTAPPLICATION_H

#include "QwtAppImpl.h"
#include "QwtPlotterWindow.h"

#include <memory>

namespace NSApplication {

namespace NSQwtPlotter {

class QwtApplication {
public:
  QwtApplication();
  void show();

private:
  std::unique_ptr<MainWindow> MainWindow_{nullptr};
  std::unique_ptr<QwtAppImpl> AppImpl_{nullptr};
};

} // namespace NSQwtPlotter

} // namespace NSApplication

#endif // QWTAPPLICATION_H
