#ifndef CONTROLLERIMPL_H
#define CONTROLLERIMPL_H

#include "PlotMaker.h"
#include "Types.h"

namespace NSApplication {

namespace NSQwtPlotter {

namespace NSDetail {

class ControllerImpl {
public:
  explicit ControllerImpl(PlotMaker::ControlFunctionPtr control_method);
  CheckboxState::CObserver* getCheckboxStateInput();

private:
  PlotMaker::ControlFunctionPtr ControlFunction_{nullptr};
  CheckboxState::CObserver CheckboxStateInput_;
};

} // namespace NSDetail

} // namespace NSQwtPlotter

} // namespace NSApplication

#endif // CONTROLLERIMPL_H
