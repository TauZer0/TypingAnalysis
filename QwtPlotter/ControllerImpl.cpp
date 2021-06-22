#include "ControllerImpl.h"

namespace NSApplication {

namespace NSQwtPlotter {

namespace NSDetail {

ControllerImpl::ControllerImpl(PlotMakerImpl* plot_maker)
    : PlotMaker_(plot_maker),
      CheckboxStateInput_([plot_maker](CheckboxState checkbox_state) {
        plot_maker->controlPlot(checkbox_state);
      }) {
}

CheckboxState::CObserver* ControllerImpl::getCheckboxStateInput() {
  return &CheckboxStateInput_;
}

} // namespace NSDetail

} // namespace NSQwtPlotter

} // namespace NSApplication
