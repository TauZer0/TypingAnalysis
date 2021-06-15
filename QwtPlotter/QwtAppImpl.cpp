#include "QwtAppImpl.h"

namespace NSApplication::NSQwtPlotter {

AppImpl::AppImpl(QtResources* qt_resources)
    : plotter_(qt_resources), controller_(&plot_maker_) {

  plotter_.subscribeFlag(controller_.getBoolInput());
  plot_maker_.subscribeText(plotter_.getTextInput());
  plot_maker_.subscribePlot(plotter_.getPlotInput());
}

} // namespace NSApplication::NSQwtPlotter
