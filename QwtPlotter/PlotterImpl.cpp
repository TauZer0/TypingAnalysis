#include "PlotterImpl.h"
#include "Support/Profiler.h"

namespace NSApplication::NSQwtPlotter {

namespace NSDetail {

PlotterImpl::PlotterImpl(MainWindow* main_window)
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

  CheckboxStateOutput_.setSource([this]() { return std::ref(CheckboxState_); });
  Plot1_->connectToSlot(this, &PlotterImpl::processCheckbox1);
  Plot2_->connectToSlot(this, &PlotterImpl::processCheckbox2);
  Plot3_->connectToSlot(this, &PlotterImpl::processCheckbox3);
}

DataRefHolder::CObserver* PlotterImpl::getDataInput() {
  return &DataInput_;
}

TextHolder::CObserver* PlotterImpl::getTextInput() {
  return &TextInput_;
}

void PlotterImpl::subscribeCheckboxState(CheckboxState::CObserver* obs) {
  CheckboxStateOutput_.subscribe(obs);
}

void PlotterImpl::processCheckbox1() {
  processCheckboxImpl(static_cast<QCheckBox*>(sender()), CheckboxState_.Plot1);
}

void PlotterImpl::processCheckbox2() {
  processCheckboxImpl(static_cast<QCheckBox*>(sender()), CheckboxState_.Plot2);
}

void PlotterImpl::processCheckbox3() {
  processCheckboxImpl(static_cast<QCheckBox*>(sender()), CheckboxState_.Plot3);
}

void PlotterImpl::processCheckboxImpl(QCheckBox* checkbox, bool& is_visible) {
  NSSupport::LOG_DURATION("Replot duration");
  if (checkbox->isChecked()) {
    is_visible = true;
  } else {
    is_visible = false;
  }
  CheckboxStateOutput_.notify();
}

void PlotterImpl::replot(const DataRefHolder& functions_data) {
  setPlot(*Plot1_, functions_data.OptionalData1);
  setPlot(*Plot2_, functions_data.OptionalData2);
  setPlot(*Plot3_, functions_data.OptionalData3);
  QtResources_->replot();
}

void PlotterImpl::setPlot(FunctionPlot& plot, OptionalRef<FunctionData> data) {
  if (data.has_value()) {
    plot.setData(data.value().get());
    plot.show();
  } else {
    plot.hide();
  }
}

} // namespace NSDetail

} // namespace NSApplication::NSQwtPlotter
