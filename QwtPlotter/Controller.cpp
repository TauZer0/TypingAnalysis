#include "Controller.h"

namespace NSApplication::NSQwtPlotter {

Controller::Controller(PlotMaker* plot_maker)
    : plot_maker_(plot_maker), bool_input_([plot_maker](Flags visible) {
        plot_maker->controlPlot(visible.plot1_, visible.plot2_);
      }) {
}

CObserverFlags* Controller::getBoolInput() {
  return &bool_input_;
}

} // namespace NSApplication::NSQwtPlotter
