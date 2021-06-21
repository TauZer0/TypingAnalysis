#ifndef CONTROLLERIMPL_H
#define CONTROLLERIMPL_H

#include "PlotMakerImpl.h"
#include "Types.h"

namespace NSApplication::NSQwtPlotter {

namespace NSDetail {

class ControllerImpl {
public:
  explicit ControllerImpl(PlotMakerImpl* plot_maker);
  CheckboxState::CObserver* getCheckboxStateInput();

private:
  PlotMakerImpl* PlotMaker_{nullptr};
  CheckboxState::CObserver CheckboxStateInput_;
};

} // namespace NSDetail

} // namespace NSApplication::NSQwtPlotter

#endif // CONTROLLERIMPL_H
