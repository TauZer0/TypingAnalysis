#include "Controller.h"

namespace NSApplication::NSQwtPlotter {

void noop(std::optional<bool>) {
}

Controller::Controller(PlotMaker* plot_maker)
    : plot_maker_(plot_maker),
      bool_input_(
          [plot_maker](std::optional<bool> flag) {
              plot_maker->controlPlot(*flag);
          },
          [plot_maker](std::optional<bool> flag) {
              plot_maker->controlPlot(*flag);
          },
          noop
      ) {
}

CObserverFlag* Controller::getBoolInput() {
    return &bool_input_;
}

}  // namespace NSApplication::NSQwtPlotter
