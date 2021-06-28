#include "Controller.h"

//#include "ControllerImpl.h"

namespace NSApplication {

namespace NSQwtPlotter {

Controller::Controller(PlotMaker::ControlFunctionPtr control_function)
    : Impl_(std::make_unique<NSDetail::ControllerImpl>(control_function)) {
}

CheckboxState::CObserver* Controller::getCheckboxStateInput() {
  return Impl_->getCheckboxStateInput();
}

} // namespace NSQwtPlotter

} // namespace NSApplication
