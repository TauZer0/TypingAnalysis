#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "ControllerImpl.h"

#include <memory>

namespace NSApplication {

namespace NSQwtPlotter {

// namespace NSDetail {

// class ControllerImpl;

//}

class Controller {
public:
  explicit Controller(PlotMaker::ControlFunctionPtr control_function);
  CheckboxState::CObserver* getCheckboxStateInput();

private:
  std::unique_ptr<NSDetail::ControllerImpl> Impl_;
};

} // namespace NSQwtPlotter

} // namespace NSApplication

#endif // CONTROLLER_H
