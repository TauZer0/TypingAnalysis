#include "FunctionWithIntervalsPlot.h"

namespace NSApplication::NSQwtPlotter {

FunctionWithIntervalsPlot::FunctionWithIntervalsPlot(QwtPlot* source,
                                                     QVBoxLayout* vbox)
    : FunctionPlot(source, vbox), source_(source) {
  assert(source_ != nullptr);
}

const std::vector<std::unique_ptr<QwtPlotCurve>>&
FunctionWithIntervalsPlot::getQwtIntervals() const {
  return qwt_intervals_;
}

void FunctionWithIntervalsPlot::setFunctionWithIntervalsPlot(
    const FunctionWithIntervalsData& function_data) {
  setFunctionPlot(function_data);
  setQwtIntervals(function_data);
}

void FunctionWithIntervalsPlot::resizeQwtIntervals(size_t n) {
  qwt_intervals_.reserve(n);
  for (size_t i = 0; i < n; ++i) {
    qwt_intervals_.emplace_back(std::make_unique<QwtPlotCurve>());
  }
}

void FunctionWithIntervalsPlot::initQwtInterval(size_t i) {
  qwt_intervals_[i]->setItemAttribute(QwtPlotItem::Legend, false);
  qwt_intervals_[i]->attach(source_);
}

void FunctionWithIntervalsPlot::setQwtInterval(size_t i,
                                               const CurveData& interval_data,
                                               const QColor& color) {
  qwt_intervals_[i]->setRawSamples(interval_data.dataX(), interval_data.dataY(),
                                   interval_data.dataSize());
  qwt_intervals_[i]->setBrush(color);
  qwt_intervals_[i]->show();
}

void FunctionWithIntervalsPlot::setQwtIntervals(
    const FunctionWithIntervalsData& function_data) {
  size_t n = function_data.getIntervalsDataSize();
  QColor alpha_color{function_data.getColor()};
  alpha_color.setAlpha(function_data.getIntervalsOpacity());
  resizeQwtIntervals(n);
  for (size_t i = 0; i < n; ++i) {
    initQwtInterval(i);
    setQwtInterval(i, function_data.getIntervalData(i), alpha_color);
  }
}

void FunctionWithIntervalsPlot::show() {
  FunctionPlot::show();
  for (auto& interval : qwt_intervals_) {
    interval->show();
  }
}

void FunctionWithIntervalsPlot::hide() {
  FunctionPlot::hide();
  for (auto& interval : qwt_intervals_) {
    interval->hide();
  }
}

} // namespace NSApplication::NSQwtPlotter
