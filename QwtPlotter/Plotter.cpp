#include "Plotter.h"
#include "Support/Profiler.h"

namespace NSApplication::NSQwtPlotter {

void processData(DataRefHolder& functions_data, QtResources* qt_resources) {

  // TODO
  if (functions_data.OptionalData1.has_value()) {
    qt_resources->showFunctionPlot1(functions_data.OptionalData1.value().get());
  } else {
    qt_resources->hideFunctionPlot1();
  }

  if (functions_data.OptionalData2.has_value()) {
    qt_resources->showFunctionPlot2(functions_data.OptionalData2.value().get());
  } else {
    qt_resources->hideFunctionPlot2();
  }

  if (functions_data.OptionalData3.has_value()) {
    qt_resources->showFunctionPlot3(functions_data.OptionalData3.value().get());
  } else {
    qt_resources->hideFunctionPlot3();
  }

  NSSupport::LOG_DURATION("Replot duration");
  qt_resources->replot();
}

Plotter::Plotter(MainWindow* main_window)
    : MainWindow_(main_window), QtResources_(main_window->getQtResources()),
      DataInput_(
          [main_window](DataRefHolder function_data) {
            processData(function_data, main_window->getQtResources());
            main_window->getQtResources()->updateZoomerBase();
          },
          [main_window](DataRefHolder function_data) {
            processData(function_data, main_window->getQtResources());
          }),
      TextInput_([main_window](TextHolder text_data) {
        main_window->setWindowTitle(text_data.Title.data());
        main_window->getQtResources()->getFunctionPlot1().setName(
            text_data.NamePlot1);
        main_window->getQtResources()->getFunctionPlot2().setName(
            text_data.NamePlot2);
        main_window->getQtResources()->getFunctionPlot3().setName(
            text_data.NamePlot3);
      }) {
  VisibilityFlagsOutput_.setSource(
      [this]() { return std::ref(VisibilityFlags_); });
  QtResources_->getFunctionPlot1().connectToSlot(this,
                                                 &Plotter::processCheckbox1);
  QtResources_->getFunctionPlot2().connectToSlot(this,
                                                 &Plotter::processCheckbox2);
  QtResources_->getFunctionPlot3().connectToSlot(this,
                                                 &Plotter::processCheckbox3);
}

DataRefHolder::CObserver* Plotter::getDataInput() {
  return &DataInput_;
}

TextHolder::CObserver* Plotter::getTextInput() {
  return &TextInput_;
}

void Plotter::subscribeVisibilityFlags(VisibilityFlags::CObserver* obs) {
  VisibilityFlagsOutput_.subscribe(obs);
}

void Plotter::processCheckbox1() {
  processCheckboxImpl(static_cast<QCheckBox*>(sender()),
                      VisibilityFlags_.Plot1);
}

void Plotter::processCheckbox2() {
  processCheckboxImpl(static_cast<QCheckBox*>(sender()),
                      VisibilityFlags_.Plot2);
}

void Plotter::processCheckbox3() {
  processCheckboxImpl(static_cast<QCheckBox*>(sender()),
                      VisibilityFlags_.Plot3);
}

void Plotter::processCheckboxImpl(QCheckBox* checkbox, bool& is_visible) {
  if (checkbox->isChecked()) {
    is_visible = true;
  } else {
    is_visible = false;
  }
  VisibilityFlagsOutput_.notify();
}

} // namespace NSApplication::NSQwtPlotter
