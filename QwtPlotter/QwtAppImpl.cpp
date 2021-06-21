#include "QwtAppImpl.h"

namespace NSApplication::NSQwtPlotter {

QwtAppImpl::QwtAppImpl(MainWindow* main_window)
    : Plotter_(main_window), Controller_(&PlotMaker_) {

  Plotter_.subscribeCheckboxState(Controller_.getCheckboxStateInput());
  PlotMaker_.subscribeText(Plotter_.getTextInput());
  PlotMaker_.subscribePlot(Plotter_.getDataInput());
}

} // namespace NSApplication::NSQwtPlotter
