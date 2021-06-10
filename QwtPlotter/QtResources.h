#ifndef QRESOURCES_H
#define QRESOURCES_H

#include "FunctionPlot.h"
#include "Zoomer.h"

#include <qwt_legend.h>
#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include <qwt_plot_grid.h>
#include <qwt_plot_magnifier.h>
#include <qwt_plot_panner.h>

#include <QCheckBox>

namespace NSApplication::NSQwtPlotter {

class QtResources {
 public:
    QtResources(QwtPlot* source, QVBoxLayout* vbox);

    FunctionPlot& GetFunctionPlot1();

 private:
    void InitGrid(QwtPlot* source);
    void InitLegend(QwtPlot* source);
    void InitMagnifier();
    void InitPanner();
    void InitZoomer();

 public:
    QwtPlot* source_{nullptr};

    QwtPlotGrid grid_;
    QwtLegend legend_;
    QwtPlotMagnifier magnifier_;
    QwtPlotPanner panner_;
    Zoomer zoomer_;

    FunctionPlot plot1_;
};

}  // namespace NSApplication::NSQwtPlotter

#endif // QRESOURCES_H
