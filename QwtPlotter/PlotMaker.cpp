#include "PlotMaker.h"

#include "FunctionTable.h"

#include <mutex>

namespace NSApplication::NSQwtPlotter {

static FunctionTable function_table;

static constexpr double kBegin = 0.0;
static constexpr double kEnd = 5.0;
static constexpr double kStep = 0.001;

PlotMaker::PlotMaker()
    : Data1_(kBegin, kEnd, kStep, function_table["sin"], Qt::red),
      Data2_(kBegin, kEnd, kStep, function_table["cos"], Qt::green) {
  double interval1_begin = 0.0;
  double interval1_end = 1.0;
  double interval2_begin = 0.5;
  double interval2_end = 4.0;
  Data2_.createIntervalData(interval1_begin, interval1_end);
  Data2_.createIntervalData(interval2_begin, interval2_end);

  TextPort_.set(TextHolder{.title_ = "QwtPlotter",
                           .plot1_name_ = "sin(x)",
                           .plot2_name_ = "cos(x)"});
}

void PlotMaker::subscribePlot(CObserverRefHolder* obs) {
  assert(obs != nullptr);
  DataPort_.subscribe(obs);
}

void PlotMaker::subscribeText(CObserverText* obs) {
  assert(obs != nullptr);
  TextPort_.subscribe(obs);
}

void PlotMaker::controlPlot(bool show_plot1, bool show_plot2) {
  if (Suppressor_.isActive()) {
    return;
  }

  std::lock_guard guard(Suppressor_);
  setRef(DataRefs_.optional_ref1_, Data1_, show_plot1);
  setRef(DataRefs_.optional_ref2_, Data2_, show_plot2);

  DataPort_.set(DataRefs_);
}

} // namespace NSApplication::NSQwtPlotter
