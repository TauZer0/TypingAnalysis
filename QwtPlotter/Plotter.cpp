#include "Plotter.h"
#include "Support/Profiler.h"

namespace NSApplication::NSQwtPlotter {

Plotter::Plotter(MainWindow* main_window)
    : MainWindow_(main_window), QtResources_(MainWindow_->getQtResources()),
      Plot1_(QtResources_->getFunctionPlot1()),
      Plot2_(QtResources_->getFunctionPlot2()),
      Plot3_(QtResources_->getFunctionPlot3()),
      DataInput_(
          [this](DataRefHolder data) {
            replot(data);
            QtResources_->updateZoomerBase();
          },
          [this](DataRefHolder data) { replot(data); }),
      TextInput_([this](TextHolder text_data) {
        MainWindow_->setWindowTitle(text_data.Title.data());
        Plot1_->setName(text_data.NamePlot1);
        Plot2_->setName(text_data.NamePlot2);
        Plot3_->setName(text_data.NamePlot3);
      }) {

  assert(MainWindow_ != nullptr);
  assert(QtResources_ != nullptr);
  assert(Plot1_ != nullptr);
  assert(Plot2_ != nullptr);
  assert(Plot3_ != nullptr);

  VisibilityFlagsOutput_.setSource(
      [this]() { return std::ref(VisibilityFlags_); });
  Plot1_->connectToSlot(this, &Plotter::processCheckbox1);
  Plot2_->connectToSlot(this, &Plotter::processCheckbox2);
  Plot3_->connectToSlot(this, &Plotter::processCheckbox3);
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
  NSSupport::LOG_DURATION("Replot duration");
  if (checkbox->isChecked()) {
    is_visible = true;
  } else {
    is_visible = false;
  }
  VisibilityFlagsOutput_.notify();
}

void Plotter::replot(const DataRefHolder& functions_data) {
  setPlot(*Plot1_, functions_data.OptionalData1);
  setPlot(*Plot2_, functions_data.OptionalData2);
  setPlot(*Plot3_, functions_data.OptionalData3);
  QtResources_->replot();
}

void Plotter::setPlot(FunctionPlot& plot, OptionalRef<FunctionData> data) {
  if (data.has_value()) {
    plot.setData(data.value().get());
    plot.show();
  } else {
    plot.hide();
  }
}

} // namespace NSApplication::NSQwtPlotter
