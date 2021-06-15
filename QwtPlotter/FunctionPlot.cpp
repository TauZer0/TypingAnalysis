#include "FunctionPlot.h"

namespace NSApplication::NSQwtPlotter {

FunctionPlot::FunctionPlot(QwtPlot* source, QVBoxLayout* vbox) {
  initQwtCurve(source);
  initCheckbox(vbox);
}

QCheckBox* FunctionPlot::getCheckbox() {
  return &checkbox_;
}

QwtPlotCurve* FunctionPlot::getQwtCurve() {
  return &qwt_curve_;
}

void FunctionPlot::setFunctionPlot(const FunctionData& function_data) {
  checkbox_.setText(function_data.getName().data());
  checkbox_.show();

  qwt_curve_.setPen(function_data.getColor());
  qwt_curve_.setTitle(function_data.getName().data());
  setQwtCurve(function_data.getCurveData());
}

void FunctionPlot::initCheckbox(QVBoxLayout* vbox) {
  vbox->addWidget(&checkbox_);
  checkbox_.setChecked(true);
  checkbox_.hide();
}

void FunctionPlot::initQwtCurve(QwtPlot* source) {
  qwt_curve_.setRenderHint(QwtPlotItem::RenderAntialiased);
  qwt_curve_.setStyle(QwtPlotCurve::Lines);
  qwt_curve_.attach(source);
}

void FunctionPlot::setQwtCurve(const CurveData& curve_data) {
  qwt_curve_.setRawSamples(curve_data.dataX(), curve_data.dataY(),
                           curve_data.dataSize());
  qwt_curve_.show();
}

void FunctionPlot::show() {
  qwt_curve_.show();
}

void FunctionPlot::hide() {
  qwt_curve_.hide();
}

} // namespace NSApplication::NSQwtPlotter
