#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "PlotMaker.h"
#include "Types.h"

namespace NSApplication::NSQwtPlotter {

class Controller {
public:
  explicit Controller(PlotMaker* plot_maker);
  CheckboxState::CObserver* getCheckboxStateInput();

private:
  PlotMaker* PlotMaker_{nullptr};
  CheckboxState::CObserver CheckboxStateInput_;
};

} // namespace NSApplication::NSQwtPlotter

#endif // CONTROLLER_H
