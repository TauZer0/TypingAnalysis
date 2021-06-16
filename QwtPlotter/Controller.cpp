#include "Controller.h"

namespace NSApplication::NSQwtPlotter {

Controller::Controller(PlotMaker* plot_maker)
    : PlotMaker_(plot_maker), BoolInput_([plot_maker](Flags visible) {
        plot_maker->controlPlot(visible.plot1_, visible.plot2_);
      }) {
}

CObserverFlags* Controller::getBoolInput() {
  return &BoolInput_;
}

} // namespace NSApplication::NSQwtPlotter
