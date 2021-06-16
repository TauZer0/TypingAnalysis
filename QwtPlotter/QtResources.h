#ifndef QRESOURCES_H
#define QRESOURCES_H

#include "FunctionPlot.h"
#include "FunctionWithIntervalsPlot.h"
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

  FunctionPlot& getFunctionPlot1();
  FunctionWithIntervalsPlot& getFunctionPlot2();
  void setFunctionPlot1(const FunctionData& function_data);
  void setFunctionPlot2(const FunctionWithIntervalsData& function_data);

  void replot();
  void updateZoomerBase();

private:
  void initGrid(QwtPlot* source);
  void initLegend(QwtPlot* source);
  void initMagnifier();
  void initPanner();
  void initZoomer();

private:
  QwtPlot* Source_{nullptr};

  QwtPlotGrid Grid_;
  QwtLegend Legend_;
  QwtPlotMagnifier Magnifier_;
  QwtPlotPanner Panner_;
  Zoomer Zoomer_;

  FunctionPlot Plot1_;
  FunctionWithIntervalsPlot Plot2_;
};

} // namespace NSApplication::NSQwtPlotter

#endif // QRESOURCES_H
