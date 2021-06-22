#include "PlotMakerImpl.h"

#include "FunctionTable.h"

#include <mutex>

namespace NSApplication {

namespace NSQwtPlotter {

namespace NSDetail {

PlotMakerImpl::PlotMakerImpl()
    : Data1_(kBegin_, kEnd_, kStep_, kFunctionTable_["sin"], Qt::red),
      Data2_(kBegin_, kEnd_, kStep_, kFunctionTable_["ln"], Qt::blue),
      Data3_(kBegin_, kEnd_, kStep_, kFunctionTable_["cos"], Qt::green) {
  double interval1_begin = 0.0;
  double interval1_end = 1.0;
  double interval2_begin = 0.5;
  double interval2_end = 4.0;
  Data3_.createIntervalData(interval1_begin, interval1_end);
  Data3_.createIntervalData(interval2_begin, interval2_end);

  TextOutput_.set(TextHolder{"QwtPlotter", "sin(x)", "ln(x)", "cos(x)"});
}

void PlotMakerImpl::subscribePlot(DataRefHolder::CObserver* obs) {
  assert(obs != nullptr);
  DataOutput_.subscribe(obs);
}

void PlotMakerImpl::subscribeText(TextHolder::CObserver* obs) {
  assert(obs != nullptr);
  TextOutput_.subscribe(obs);
}

void PlotMakerImpl::controlPlot(const CheckboxState& checkbox_state) {
  if (Suppressor_.isActive()) {
    return;
  }

  std::lock_guard guard(Suppressor_);
  setRef(DataRefs_.OptionalData1, Data1_, checkbox_state.Plot1);
  setRef(DataRefs_.OptionalData2, Data2_, checkbox_state.Plot2);
  setRef(DataRefs_.OptionalData3, Data3_, checkbox_state.Plot3);
  DataOutput_.set(DataRefs_);
}

} // namespace NSDetail

} // namespace NSQwtPlotter

} // namespace NSApplication
