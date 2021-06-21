#include "PlotMaker.h"

namespace NSApplication::NSQwtPlotter {

PlotMaker::PlotMaker() : Impl_(std::make_unique<NSDetail::PlotMakerImpl>()) {
}

void PlotMaker::controlPlot(const CheckboxState& checkbox_state) {
  Impl_->controlPlot(checkbox_state);
}

void PlotMaker::subscribePlot(DataRefHolder::CObserver* obs) {
  Impl_->subscribePlot(obs);
}

void PlotMaker::subscribeText(TextHolder::CObserver* obs) {
  Impl_->subscribeText(obs);
}

NSDetail::PlotMakerImpl* PlotMaker::getImpl() {
  return Impl_.get();
}

} // namespace NSApplication::NSQwtPlotter
