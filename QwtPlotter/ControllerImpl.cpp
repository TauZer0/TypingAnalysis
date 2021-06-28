#include "ControllerImpl.h"

namespace NSApplication {

namespace NSQwtPlotter {

namespace NSDetail {

ControllerImpl::ControllerImpl(PlotMaker::ControlFunctionPtr control_method)
    : ControlFunction_(control_method),
      CheckboxStateInput_([this](CheckboxState checkbox_state) {
        ControlFunction_(checkbox_state);
      }) {
}

CheckboxState::CObserver* ControllerImpl::getCheckboxStateInput() {
  return &CheckboxStateInput_;
}

} // namespace NSDetail

} // namespace NSQwtPlotter

} // namespace NSApplication
