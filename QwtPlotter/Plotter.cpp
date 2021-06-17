#include "Plotter.h"
#include "Support/Profiler.h"

namespace NSApplication::NSQwtPlotter {

void processData(DataRefHolder& functions_data, QtResources* qt_resources) {

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
  qt_resources->updateZoomerBase(); // FIXME
}

Plotter::Plotter(MainWindow* main_window)
    : MainWindow_(main_window), QtResources_(main_window->getQtResources()),
      ObserverPlot_([main_window](DataRefHolder function_data) {
        processData(function_data, main_window->getQtResources());
      }),
      ObserverText_([main_window](TextHolder text_data) {
        main_window->setWindowTitle(text_data.title_.data());
        main_window->getQtResources()->getFunctionPlot1().setName(
            text_data.plot1_name_);
        main_window->getQtResources()->getFunctionPlot2().setName(
            text_data.plot2_name_);
      }) {
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
