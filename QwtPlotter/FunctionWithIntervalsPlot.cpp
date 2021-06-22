#include "FunctionWithIntervalsPlot.h"

namespace NSApplication {

namespace NSQwtPlotter {

FunctionWithIntervalsPlot::FunctionWithIntervalsPlot(QwtPlot* source,
                                                     QVBoxLayout* vbox)
    : FunctionPlot(source, vbox), Source_(source) {
  assert(Source_ != nullptr);
}

const std::vector<std::unique_ptr<QwtPlotCurve>>&
FunctionWithIntervalsPlot::getQwtIntervals() const {
  return QwtIntervals_;
}

void FunctionWithIntervalsPlot::setData(const FunctionData& function_data) {
  FunctionPlot::setData(function_data);
  setQwtIntervals(static_cast<const FunctionWithIntervalsData&>(function_data));
}

void FunctionWithIntervalsPlot::resizeQwtIntervals(size_t n) {
  QwtIntervals_.reserve(n);
  for (size_t i = 0; i < n; ++i) {
    QwtIntervals_.emplace_back(std::make_unique<QwtPlotCurve>());
  }
}

void FunctionWithIntervalsPlot::initQwtInterval(size_t i) {
  QwtIntervals_[i]->setItemAttribute(QwtPlotItem::Legend, false);
  QwtIntervals_[i]->attach(Source_);
}

void FunctionWithIntervalsPlot::setQwtInterval(size_t i,
                                               const CurveData& interval_data,
                                               const QColor& color) {
  QwtIntervals_[i]->setRawSamples(interval_data.dataX(), interval_data.dataY(),
                                  interval_data.dataSize());
  QwtIntervals_[i]->setBrush(color);
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
  for (auto& interval : QwtIntervals_) {
    interval->show();
  }
}

void FunctionWithIntervalsPlot::hide() {
  FunctionPlot::hide();
  for (auto& interval : QwtIntervals_) {
    interval->hide();
  }
}

} // namespace NSQwtPlotter

} // namespace NSApplication
