#include "Controller.h"

namespace NSApplication::NSQwtPlotter {

Controller::Controller(PlotMaker* plot_maker)
    : PlotMaker_(plot_maker),
      VisibilityFlagsInput_([plot_maker](VisibilityFlags visibility) {
        plot_maker->controlPlot(visibility);
      }) {
}

VisibilityFlags::CObserver* Controller::getVisibilityFlagsInput() {
  return &VisibilityFlagsInput_;
}

} // namespace NSApplication::NSQwtPlotter
