#include "Plotter.h"

namespace NSApplication::NSQwtPlotter {

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

  qt_resources->replot();
  qt_resources->updateZoomerBase();
}

Plotter::Plotter(QtResources* qt_resources)
    : qt_resources_(qt_resources),
      observer_plot_([qt_resources](RefHolder function_data) {
        processData(function_data, qt_resources);
      }),
      observer_text_(noop<Text>, noop<Text>, noop<Text>) {
  flags_output_.setSource([this]() { return std::ref(visible_plots_); });
  qt_resources_->getFunctionPlot1().connectToSlot(this,
                                                  &Plotter::processCheckbox1);
  qt_resources_->getFunctionPlot2().connectToSlot(this,
                                                  &Plotter::processCheckbox2);
}

CObserverRefHolder* Plotter::getPlotInput() {
  return &observer_plot_;
}

CObserverText* Plotter::getTextInput() {
  return &observer_text_;
}

void Plotter::subscribeFlag(CObserverFlags* obs) {
  flags_output_.subscribe(obs);
}

void Plotter::processCheckbox1() {
  QCheckBox* checkbox = static_cast<QCheckBox*>(sender());

  if (checkbox->isChecked()) {
    visible_plots_.plot1_ = true;
  } else {
    visible_plots_.plot1_ = false;
  }
  flags_output_.notify();
}

void Plotter::processCheckbox2() {
  QCheckBox* checkbox = static_cast<QCheckBox*>(sender());

  if (checkbox->isChecked()) {
    visible_plots_.plot2_ = true;
  } else {
    visible_plots_.plot2_ = false;
  }
  flags_output_.notify();
}

} // namespace NSApplication::NSQwtPlotter
