#ifndef QWTAPPIMPL_H
#define QWTAPPIMPL_H

#include "Controller.h"
#include "PlotMaker.h"
#include "Plotter.h"
#include "QtResources.h"

namespace NSApplication::NSQwtPlotter {

class QwtAppImpl {
public:
  explicit QwtAppImpl(MainWindow* main_window);

private:
  PlotMaker PlotMaker_;
  Plotter Plotter_;
  Controller Controller_;
};

} // namespace NSApplication::NSQwtPlotter

#endif // QWTAPPIMPL_H
