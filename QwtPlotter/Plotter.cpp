#include "Plotter.h"
#include "Support/Profiler.h"

namespace NSApplication::NSQwtPlotter {

// TODO
void Plotter::replot(const DataRefHolder& data) {
  NSSupport::LOG_DURATION("Replot duration");
  if (data.OptionalData1.has_value()) {
    Plot1_->setData(data.OptionalData1.value().get());
    Plot1_->show();
  } else {
    Plot1_->hide();
  }

  if (data.OptionalData2.has_value()) {
    Plot2_->setData(data.OptionalData2.value().get());
    Plot2_->show();
  } else {
    Plot2_->hide();
  }

  if (data.OptionalData3.has_value()) {
    Plot3_->setDataWithIntervals(data.OptionalData3.value().get());
    Plot3_->show();
  } else {
    Plot3_->hide();
  }

  QtResources_->replot();
}

Plotter::Plotter(MainWindow* main_window)
    : MainWindow_(main_window), QtResources_(main_window->getQtResources()),
      Plot1_(QtResources_->getFunctionPlot1()),
      Plot2_(QtResources_->getFunctionPlot2()),
      Plot3_(QtResources_->getFunctionPlot3()),
      DataInput_(
          [this](DataRefHolder data) {
            Plotter::replot(data);
            this->QtResources_->updateZoomerBase();
          },
          [this](DataRefHolder data) { Plotter::replot(data); }),
      TextInput_([this](TextHolder text_data) {
        this->MainWindow_->setWindowTitle(text_data.Title.data());
        this->Plot1_->setName(text_data.NamePlot1);
        this->Plot2_->setName(text_data.NamePlot2);
        this->Plot3_->setName(text_data.NamePlot3);
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
  if (checkbox->isChecked()) {
    is_visible = true;
  } else {
    is_visible = false;
  }
  VisibilityFlagsOutput_.notify();
}

} // namespace NSApplication::NSQwtPlotter
