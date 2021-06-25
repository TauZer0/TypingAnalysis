#include "Controller.h"

//#include "ControllerImpl.h"

namespace NSApplication {

namespace NSQwtPlotter {

Controller::Controller(PlotMaker* plot_maker)
    : Impl_(std::make_unique<NSDetail::ControllerImpl>(plot_maker->getImpl())) {
}

CheckboxState::CObserver* Controller::getCheckboxStateInput() {
  return Impl_->getCheckboxStateInput();
}

} // namespace NSQwtPlotter

} // namespace NSApplication
