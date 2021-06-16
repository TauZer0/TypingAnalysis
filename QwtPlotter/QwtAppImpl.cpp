#include "QwtAppImpl.h"

namespace NSApplication::NSQwtPlotter {

AppImpl::AppImpl(QtResources* qt_resources)
    : Plotter_(qt_resources), Controller_(&PlotMaker_) {

  Plotter_.subscribeFlag(Controller_.getBoolInput());
  PlotMaker_.subscribeText(Plotter_.getTextInput());
  PlotMaker_.subscribePlot(Plotter_.getPlotInput());
}

} // namespace NSApplication::NSQwtPlotter
