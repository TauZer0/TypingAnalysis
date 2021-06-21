#include "Plotter.h"

#include "PlotterImpl.h"
#include "Support/Profiler.h"

namespace NSApplication::NSQwtPlotter {

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

// void Plotter::processCheckbox1() {
//  Impl_->processCheckbox1(static_cast<QCheckBox*>(sender()));
//}

// void Plotter::processCheckbox2() {
//  Impl_->processCheckbox2(static_cast<QCheckBox*>(sender()));
//}

// void Plotter::processCheckbox3() {
//  Impl_->processCheckbox3(static_cast<QCheckBox*>(sender()));
//}

} // namespace NSApplication::NSQwtPlotter
