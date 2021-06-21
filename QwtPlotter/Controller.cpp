#include "Controller.h"

namespace NSApplication::NSQwtPlotter {

Controller::Controller(PlotMaker* plot_maker)
    : Impl_(std::make_unique<NSDetail::ControllerImpl>(plot_maker->getImpl())) {
}

CheckboxState::CObserver* Controller::getCheckboxStateInput() {
  return Impl_->getCheckboxStateInput();
}

} // namespace NSApplication::NSQwtPlotter
