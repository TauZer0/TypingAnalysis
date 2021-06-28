#include "QwtAppImpl.h"

namespace NSApplication {

namespace NSQwtPlotter {

QwtAppImpl::QwtAppImpl(MainWindow* main_window)
    : Plotter_(main_window), Controller_(PlotMaker_.getControlFunction()) {

  Plotter_.subscribeCheckboxState(Controller_.getCheckboxStateInput());
  PlotMaker_.subscribeText(Plotter_.getTextInput());
  PlotMaker_.subscribePlot(Plotter_.getDataInput());
}

} // namespace NSQwtPlotter

} // namespace NSApplication
