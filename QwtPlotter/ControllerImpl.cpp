#include "ControllerImpl.h"

namespace NSApplication {

namespace NSQwtPlotter {

namespace NSDetail {

ControllerImpl::ControllerImpl(PlotMakerImpl* plot_maker)
    : PlotMaker_(plot_maker),
      CheckboxStateInput_([plot_maker](CheckboxState visibility) {
        plot_maker->controlPlot(visibility);
      }) {
}

CheckboxState::CObserver* ControllerImpl::getCheckboxStateInput() {
  return &CheckboxStateInput_;
}

} // namespace NSDetail

} // namespace NSQwtPlotter

} // namespace NSApplication
