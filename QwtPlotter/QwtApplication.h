#ifndef QWTAPPLICATION_H
#define QWTAPPLICATION_H

#include "QwtAppImpl.h"
#include "QwtPlotterWindow.h"

#include <memory>

namespace NSApplication::NSQwtPlotter {

class QwtApplication {
public:
    QwtApplication();
    void show();

private:
    std::unique_ptr<MainWindow> main_window_{nullptr};
    std::unique_ptr<AppImpl> app_impl_{nullptr};
};

}  // namespace NSApplication::NSQwtPlotter

#endif // QWTAPPLICATION_H
