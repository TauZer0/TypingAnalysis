#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "ControllerImpl.h"
#include "PlotMaker.h"

#include <memory>

namespace NSApplication::NSQwtPlotter {

class Controller {
public:
  explicit Controller(PlotMaker* plot_maker);
  CheckboxState::CObserver* getCheckboxStateInput();

private:
  std::unique_ptr<NSDetail::ControllerImpl> Impl_;
};

} // namespace NSApplication::NSQwtPlotter

#endif // CONTROLLER_H
