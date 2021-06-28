#include "PlotMaker.h"

//#include "PlotMakerImpl.h"

namespace NSApplication {

namespace NSQwtPlotter {

PlotMaker::PlotMaker() : Impl_(std::make_unique<NSDetail::PlotMakerImpl>()) {
}

void PlotMaker::subscribePlot(DataRefHolder::CObserver* obs) {
  Impl_->subscribePlot(obs);
}

void PlotMaker::subscribeText(TextHolder::CObserver* obs) {
  Impl_->subscribeText(obs);
}

PlotMaker::ControlFunctionPtr PlotMaker::getControlFunction() const {
  return NSDetail::PlotMakerImpl::controlPlot;
}

} // namespace NSQwtPlotter

} // namespace NSApplication
