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
  PlotMaker* plot_maker_{nullptr};
  CObserverFlags bool_input_;
};

} // namespace NSApplication::NSQwtPlotter

#endif // CONTROLLER_H
