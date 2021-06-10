#include "QtResources.h"

namespace NSApplication::NSQwtPlotter {

QtResources::QtResources(QwtPlot* source, QVBoxLayout* vbox)
    : source_(source),
      magnifier_(source->canvas()),
      panner_(source->canvas()),
      zoomer_(source->canvas()),
      plot1_(source, vbox) {
    assert(source != nullptr);
    assert(vbox != nullptr);
    initGrid(source);
    initLegend(source);
    initMagnifier();
    initPanner();
    initZoomer();
}

void QtResources::initGrid(QwtPlot* source) {
    grid_.enableXMin(true);
    grid_.enableYMin(true);
    grid_.setMajorPen(QPen(Qt::black, 0, Qt::DotLine));
    grid_.setMinorPen(QPen(Qt::gray, 0, Qt::DotLine));
    grid_.attach(source);
}

void QtResources::initLegend(QwtPlot* source) {
    source->insertLegend(&legend_, QwtPlot::BottomLegend);
    source->setCanvasBackground(Qt::white);
    source->setAxisTitle(QwtPlot::xBottom, "X");
    source->setAxisTitle(QwtPlot::yLeft, "Y");
}

void QtResources::initMagnifier() {
    magnifier_.setMouseButton(Qt::NoButton);
    magnifier_.setWheelModifiers(Qt::ControlModifier);
}

void QtResources::initPanner() {
    panner_.setMouseButton(Qt::MiddleButton);
}

void QtResources::initZoomer() {
    zoomer_.setRubberBandPen(QPen(Qt::darkBlue));
    zoomer_.setTrackerPen(QPen(Qt::darkBlue));
    zoomer_.setMousePattern(QwtEventPattern::MouseSelect2, Qt::RightButton, Qt::ControlModifier);
    zoomer_.setMousePattern(QwtEventPattern::MouseSelect3, Qt::RightButton);
}

FunctionPlot& QtResources::getFunctionPlot1() {
    return plot1_;
}

void QtResources::setFunctionPlot1(const FunctionData& function_data) {
    plot1_.setFunctionPlot(function_data);
}

void QtResources::replot() {
    source_->replot();
}

void QtResources::updateZoomerBase() {
    zoomer_.updateBase();
}

}  // namespace NSApplication::NSQwtPlotter
