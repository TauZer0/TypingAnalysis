#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "PlotMaker.h"
#include "Types.h"

namespace NSApplication::NSQwtPlotter {

class Controller {
public:
  explicit Controller(PlotMaker* plot_maker);

  CObserverFlags* getBoolInput();

private:
  PlotMaker* PlotMaker_{nullptr};
  CObserverFlags BoolInput_;
};

} // namespace NSApplication::NSQwtPlotter

#endif // CONTROLLER_H
