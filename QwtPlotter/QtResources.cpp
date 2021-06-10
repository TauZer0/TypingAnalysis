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
    InitGrid(source);
    InitLegend(source);
    InitMagnifier();
    InitPanner();
    InitZoomer();
}

void QtResources::InitGrid(QwtPlot* source) {
    grid_.enableXMin(true);
    grid_.enableYMin(true);
    grid_.setMajorPen(QPen(Qt::black, 0, Qt::DotLine));
    grid_.setMinorPen(QPen(Qt::gray, 0, Qt::DotLine));
    grid_.attach(source);
}

void QtResources::InitLegend(QwtPlot* source) {
    source->insertLegend(&legend_, QwtPlot::BottomLegend);
    source->setCanvasBackground(Qt::white);
    source->setAxisTitle(QwtPlot::xBottom, "X");
    source->setAxisTitle(QwtPlot::yLeft, "Y");
}

void QtResources::InitMagnifier() {
    magnifier_.setMouseButton(Qt::NoButton);
    magnifier_.setWheelModifiers(Qt::ControlModifier);
}

void QtResources::InitPanner() {
    panner_.setMouseButton(Qt::MiddleButton);
}

void QtResources::InitZoomer() {
    zoomer_.setRubberBandPen(QPen(Qt::darkBlue));
    zoomer_.setTrackerPen(QPen(Qt::darkBlue));
    zoomer_.setMousePattern(QwtEventPattern::MouseSelect2, Qt::RightButton, Qt::ControlModifier);
    zoomer_.setMousePattern(QwtEventPattern::MouseSelect3, Qt::RightButton);
}

FunctionPlot& QtResources::GetFunctionPlot1() {
    return plot1_;
}

}  // namespace NSApplication::NSQwtPlotter
