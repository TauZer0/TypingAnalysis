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
  PlotMaker plot_maker_;
  Plotter plotter_;
  Controller controller_;
};

} // namespace NSApplication::NSQwtPlotter

#endif // QWTAPPIMPL_H
