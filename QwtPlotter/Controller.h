#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "PlotMaker.h"
#include "Types.h"

namespace NSApplication::NSQwtPlotter {

class Controller {
public:
  explicit Controller(PlotMaker* plot_maker);
  VisibilityFlags::CObserver* getVisibilityFlagsInput();

private:
  PlotMaker* PlotMaker_{nullptr};
  VisibilityFlags::CObserver VisibilityFlagsInput_;
};

} // namespace NSApplication::NSQwtPlotter

#endif // CONTROLLER_H
