#include "QtResources.h"

namespace NSApplication::NSQwtPlotter {

QtResources::QtResources(QwtPlot* source, QVBoxLayout* vbox)
    : Source_(source), Magnifier_(source->canvas()), Panner_(source->canvas()),
      Zoomer_(source->canvas()), Plot1_(source, vbox), Plot2_(source, vbox),
      Plot3_(source, vbox) {
  assert(source != nullptr);
  assert(vbox != nullptr);
  initGrid();
  initLegend();
  initMagnifier();
  initPanner();
  initZoomer();
}

void QtResources::initGrid() {
  Grid_.enableXMin(true);
  Grid_.enableYMin(true);
  Grid_.setMajorPen(QPen(Qt::black, 0, Qt::DotLine));
  Grid_.setMinorPen(QPen(Qt::gray, 0, Qt::DotLine));
  Grid_.attach(Source_);
}

void QtResources::initLegend() {
  Source_->insertLegend(&Legend_, QwtPlot::BottomLegend);
  Source_->setCanvasBackground(Qt::white);
  Source_->setAxisTitle(QwtPlot::xBottom, "X");
  Source_->setAxisTitle(QwtPlot::yLeft, "Y");
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

FunctionPlot* QtResources::getFunctionPlot1() {
  return &Plot1_;
}

FunctionPlot* QtResources::getFunctionPlot2() {
  return &Plot2_;
}

FunctionWithIntervalsPlot* QtResources::getFunctionPlot3() {
  return &Plot3_;
}

void QtResources::replot() {
  Source_->replot();
}

void QtResources::updateZoomerBase() {
  Zoomer_.updateBase();
}

} // namespace NSApplication::NSQwtPlotter
