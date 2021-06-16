#ifndef QWTAPPIMPL_H
#define QWTAPPIMPL_H

#include "Controller.h"
#include "PlotMaker.h"
#include "Plotter.h"
#include "QtResources.h"

namespace NSApplication::NSQwtPlotter {

class AppImpl {
public:
  explicit AppImpl(QtResources* qt_resources);

private:
  PlotMaker PlotMaker_;
  Plotter Plotter_;
  Controller Controller_;
};

} // namespace NSApplication::NSQwtPlotter

#endif // QWTAPPIMPL_H
