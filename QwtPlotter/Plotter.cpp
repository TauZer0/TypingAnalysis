#include "Plotter.h"
#include "Support/Profiler.h"

namespace NSApplication::NSQwtPlotter {

// TODO
template<typename T>
void noop(OptionalRef<const T>) {
}

void processData(RefHolder& functions_data, QtResources* qt_resources) {

  // TODO
  if (functions_data.optional_ref1_.has_value()) {
    qt_resources->setFunctionPlot1(functions_data.optional_ref1_.value().get());
    qt_resources->getFunctionPlot1().show();
  } else {
    qt_resources->getFunctionPlot1().hide();
  }

  if (functions_data.optional_ref2_.has_value()) {
    qt_resources->setFunctionPlot2(functions_data.optional_ref2_.value().get());
    qt_resources->getFunctionPlot2().show();
  } else {
    qt_resources->getFunctionPlot2().hide();
  }

  NSSupport::LOG_DURATION("Replot duration");
  qt_resources->replot();
  qt_resources->updateZoomerBase();
}

Plotter::Plotter(QtResources* qt_resources)
    : QtResources_(qt_resources),
      ObserverPlot_([qt_resources](RefHolder function_data) {
        processData(function_data, qt_resources);
      }),
      ObserverText_(noop<Text>, noop<Text>, noop<Text>) {
  FlagsOutput_.setSource([this]() { return std::ref(VisiblePlots_); });
  QtResources_->getFunctionPlot1().connectToSlot(this,
                                                 &Plotter::processCheckbox1);
  QtResources_->getFunctionPlot2().connectToSlot(this,
                                                 &Plotter::processCheckbox2);
}

CObserverRefHolder* Plotter::getPlotInput() {
  return &ObserverPlot_;
}

CObserverText* Plotter::getTextInput() {
  return &ObserverText_;
}

void Plotter::subscribeFlag(CObserverFlags* obs) {
  FlagsOutput_.subscribe(obs);
}

void Plotter::processCheckbox1() {
  processCheckboxImpl(static_cast<QCheckBox*>(sender()), VisiblePlots_.plot1_);
}

void Plotter::processCheckbox2() {
  processCheckboxImpl(static_cast<QCheckBox*>(sender()), VisiblePlots_.plot2_);
}

void Plotter::processCheckboxImpl(QCheckBox* checkbox, bool& is_visible) {
  if (checkbox->isChecked()) {
    is_visible = true;
  } else {
    is_visible = false;
  }
  FlagsOutput_.notify();
}

} // namespace NSApplication::NSQwtPlotter
