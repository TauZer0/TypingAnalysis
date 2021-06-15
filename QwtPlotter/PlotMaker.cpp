#include "PlotMaker.h"

#include "FunctionTable.h"

namespace NSApplication::NSQwtPlotter {

static FunctionTable function_table;

static constexpr double kBegin = 0.0;
static constexpr double kEnd = 5.0;
static constexpr double kStep = 0.001;

PlotMaker::PlotMaker()
    : data1_(kBegin, kEnd, kStep, function_table["sin"], "sin(x)", Qt::red),
      data2_(kBegin, kEnd, kStep, function_table["cos"], "cos(x)", Qt::green) {
  double interval1_begin = 0.0;
  double interval1_end = 1.0;
  double interval2_begin = 0.5;
  double interval2_end = 4.0;
  data2_.createIntervalData(interval1_begin, interval1_end);
  data2_.createIntervalData(interval2_begin, interval2_end);
}

void PlotMaker::subscribePlot(CObserverRefHolder* obs) {
  assert(obs != nullptr);
  data_port_.subscribe(obs);
}

void PlotMaker::subscribeText(CObserverText* obs) {
  assert(obs != nullptr);
  text_port_.subscribe(obs);
}

void PlotMaker::controlPlot(bool show_plot1, bool show_plot2) {
  if (suppressor_) {
    return;
  }

  suppressor_ = true;
  setRef(data_refs_.optional_ref1_, data1_, show_plot1);
  setRef(data_refs_.optional_ref2_, data2_, show_plot2);

  data_port_.set(data_refs_);
  suppressor_ = false;
}

} // namespace NSApplication::NSQwtPlotter
