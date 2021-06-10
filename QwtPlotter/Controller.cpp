#include "Controller.h"

namespace NSApplication::NSQwtPlotter {

Controller::Controller(PlotMaker* plot_maker)
    : plot_maker_(plot_maker),
      bools_input_(
          [](std::optional<bool>) {},
          [plot_maker](std::optional<bool> flag) {
                plot_maker->ControlPlot(flag.value(), false);
            },
          [](std::optional<bool>) {}) {
}

CObserverFlag* Controller::GetBoolsInput() {
    return &bools_input_;
}

}  // namespace NSApplication::NSQwtPlotter
