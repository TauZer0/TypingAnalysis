#include "QwtAppImpl.h"

namespace NSApplication::NSQwtPlotter {

QwtAppImpl::QwtAppImpl(MainWindow* main_window)
    : Plotter_(main_window), Controller_(&PlotMaker_) {

  Plotter_.subscribeVisibilityFlags(Controller_.getVisibilityFlagsInput());
  PlotMaker_.subscribeText(Plotter_.getTextInput());
  PlotMaker_.subscribePlot(Plotter_.getDataInput());
}

} // namespace NSApplication::NSQwtPlotter
