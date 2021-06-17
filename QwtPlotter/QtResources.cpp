#include "QtResources.h"

namespace NSApplication::NSQwtPlotter {

QtResources::QtResources(QwtPlot* source, QVBoxLayout* vbox)
    : Source_(source), Magnifier_(source->canvas()), Panner_(source->canvas()),
      Zoomer_(source->canvas()), Plot1_(source, vbox), Plot2_(source, vbox),
      Plot3_(source, vbox) {
  assert(source != nullptr);
  assert(vbox != nullptr);
  initGrid(source);
  initLegend(source);
  initMagnifier();
  initPanner();
  initZoomer();
}

void QtResources::initGrid(QwtPlot* source) {
  Grid_.enableXMin(true);
  Grid_.enableYMin(true);
  Grid_.setMajorPen(QPen(Qt::black, 0, Qt::DotLine));
  Grid_.setMinorPen(QPen(Qt::gray, 0, Qt::DotLine));
  Grid_.attach(source);
}

void QtResources::initLegend(QwtPlot* source) {
  source->insertLegend(&Legend_, QwtPlot::BottomLegend);
  source->setCanvasBackground(Qt::white);
  source->setAxisTitle(QwtPlot::xBottom, "X");
  source->setAxisTitle(QwtPlot::yLeft, "Y");
}

void QtResources::initMagnifier() {
  Magnifier_.setMouseButton(Qt::NoButton);
  Magnifier_.setWheelModifiers(Qt::ControlModifier);
}

void QtResources::initPanner() {
  Panner_.setMouseButton(Qt::MiddleButton);
}

void QtResources::initZoomer() {
  Zoomer_.setRubberBandPen(QPen(Qt::darkBlue));
  Zoomer_.setTrackerPen(QPen(Qt::darkBlue));
  Zoomer_.setMousePattern(QwtEventPattern::MouseSelect2, Qt::RightButton,
                          Qt::ControlModifier);
  Zoomer_.setMousePattern(QwtEventPattern::MouseSelect3, Qt::RightButton);
}

FunctionPlot& QtResources::getFunctionPlot1() {
  return Plot1_;
}

FunctionPlot& QtResources::getFunctionPlot2() {
  return Plot2_;
}

FunctionWithIntervalsPlot& QtResources::getFunctionPlot3() {
  return Plot3_;
}

void QtResources::showFunctionPlot1(const FunctionData& function_data) {
  Plot1_.setData(function_data);
  Plot1_.show();
}

void QtResources::showFunctionPlot2(const FunctionData& function_data) {
  Plot2_.setData(function_data);
  Plot2_.show();
}

void QtResources::showFunctionPlot3(
    const FunctionWithIntervalsData& function_data) {
  Plot3_.setDataWithIntervals(function_data);
  Plot3_.show();
}

void QtResources::hideFunctionPlot1() {
  Plot1_.hide();
}

void QtResources::hideFunctionPlot2() {
  Plot2_.hide();
}

void QtResources::hideFunctionPlot3() {
  Plot3_.hide();
}

void QtResources::replot() {
  Source_->replot();
}

void QtResources::updateZoomerBase() {
  Zoomer_.updateBase();
}

} // namespace NSApplication::NSQwtPlotter
