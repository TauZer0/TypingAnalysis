#include "PlotMaker.h"

#include "FunctionTable.h"

#include <mutex>

namespace NSApplication::NSQwtPlotter {

namespace {

static FunctionTable function_table;

static constexpr double kBegin = 0.0;
static constexpr double kEnd = 5.0;
static constexpr double kStep = 0.001;

} // namespace

PlotMaker::PlotMaker()
    : Data1_(kBegin, kEnd, kStep, function_table["sin"], Qt::red),
      Data2_(kBegin, kEnd, kStep, function_table["ln"], Qt::blue),
      Data3_(kBegin, kEnd, kStep, function_table["cos"], Qt::green) {
  double interval1_begin = 0.0;
  double interval1_end = 1.0;
  double interval2_begin = 0.5;
  double interval2_end = 4.0;
  Data3_.createIntervalData(interval1_begin, interval1_end);
  Data3_.createIntervalData(interval2_begin, interval2_end);

  TextOutput_.set(TextHolder{.Title = "QwtPlotter",
                             .NamePlot1 = "sin(x)",
                             .NamePlot2 = "ln(x)",
                             .NamePlot3 = "cos(x)"});
}

void PlotMaker::subscribePlot(DataRefHolder::CObserver* obs) {
  assert(obs != nullptr);
  DataOutput_.subscribe(obs);
}

void PlotMaker::subscribeText(TextHolder::CObserver* obs) {
  assert(obs != nullptr);
  TextOutput_.subscribe(obs);
}

void PlotMaker::controlPlot(const CheckboxState& visibility) {
  if (Suppressor_.isActive()) {
    return;
  }

  std::lock_guard guard(Suppressor_);
  setRef(DataRefs_.OptionalData1, Data1_, visibility.Plot1);
  setRef(DataRefs_.OptionalData2, Data2_, visibility.Plot2);
  setRef(DataRefs_.OptionalData3, Data3_, visibility.Plot3);
  DataOutput_.set(DataRefs_);
}

} // namespace NSApplication::NSQwtPlotter
