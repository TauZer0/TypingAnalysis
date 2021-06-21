#include "Controller.h"

namespace NSApplication::NSQwtPlotter {

Controller::Controller(PlotMaker* plot_maker)
    : PlotMaker_(plot_maker),
      CheckboxStateInput_([plot_maker](CheckboxState visibility) {
        plot_maker->controlPlot(visibility);
      }) {
}

CheckboxState::CObserver* Controller::getCheckboxStateInput() {
  return &CheckboxStateInput_;
}

} // namespace NSApplication::NSQwtPlotter
