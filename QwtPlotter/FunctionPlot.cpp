#include "FunctionPlot.h"

namespace NSApplication::NSQwtPlotter {

FunctionPlot::FunctionPlot(QwtPlot* source, QVBoxLayout* vbox) {
  initQwtCurve(source);
  initCheckbox(vbox);
}

QCheckBox* FunctionPlot::getCheckbox() {
  return &Checkbox_;
}

QwtPlotCurve* FunctionPlot::getQwtCurve() {
  return &QwtCurve_;
}

void FunctionPlot::setFunctionPlot(const FunctionData& function_data) {
  Checkbox_.setText(function_data.getName().data());
  Checkbox_.show();

  QwtCurve_.setPen(function_data.getColor());
  QwtCurve_.setTitle(function_data.getName().data());
  setQwtCurve(function_data.getCurveData());
}

void FunctionPlot::initCheckbox(QVBoxLayout* vbox) {
  vbox->addWidget(&Checkbox_);
  Checkbox_.setChecked(true);
  Checkbox_.hide();
}

void FunctionPlot::initQwtCurve(QwtPlot* source) {
  QwtCurve_.setRenderHint(QwtPlotItem::RenderAntialiased);
  QwtCurve_.setStyle(QwtPlotCurve::Lines);
  QwtCurve_.attach(source);
}

void FunctionPlot::setQwtCurve(const CurveData& curve_data) {
  QwtCurve_.setRawSamples(curve_data.dataX(), curve_data.dataY(),
                          curve_data.dataSize());
  QwtCurve_.show();
}

void FunctionPlot::show() {
  QwtCurve_.show();
}

void FunctionPlot::hide() {
  QwtCurve_.hide();
}

} // namespace NSApplication::NSQwtPlotter
