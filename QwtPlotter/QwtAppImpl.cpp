#include "QwtAppImpl.h"

namespace NSApplication::NSQwtPlotter {

QwtAppImpl::QwtAppImpl(MainWindow* main_window)
    : Plotter_(main_window), Controller_(&PlotMaker_) {

  Plotter_.subscribeFlag(Controller_.getBoolInput());
  PlotMaker_.subscribeText(Plotter_.getTextInput());
  PlotMaker_.subscribePlot(Plotter_.getPlotInput());
}

} // namespace NSApplication::NSQwtPlotter
