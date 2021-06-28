#ifndef QWTAPPIMPL_H
#define QWTAPPIMPL_H

#include "Controller.h"
#include "PlotMaker.h"
#include "Plotter.h"
#include "QwtPlotterWindow.h"

namespace NSApplication {

namespace NSQwtPlotter {

class QwtAppImpl {
public:
  explicit QwtAppImpl(MainWindow* main_window);

private:
  PlotMaker PlotMaker_;
  Plotter Plotter_;
  Controller Controller_;
};

} // namespace NSQwtPlotter

} // namespace NSApplication

#endif // QWTAPPIMPL_H
