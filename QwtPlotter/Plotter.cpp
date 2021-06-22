#include "Plotter.h"

#include "PlotterImpl.h"
#include "Support/Profiler.h"

namespace NSApplication {

namespace NSQwtPlotter {

Plotter::Plotter(MainWindow* main_window)
    : Impl_(std::make_unique<NSDetail::PlotterImpl>(main_window)) {
}

DataRefHolder::CObserver* Plotter::getDataInput() {
  return Impl_->getDataInput();
}

TextHolder::CObserver* Plotter::getTextInput() {
  return Impl_->getTextInput();
}

void Plotter::subscribeCheckboxState(CheckboxState::CObserver* obs) {
  Impl_->subscribeCheckboxState(obs);
}

} // namespace NSQwtPlotter

} // namespace NSApplication
