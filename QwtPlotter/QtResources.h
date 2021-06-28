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

namespace NSApplication {

namespace NSQwtPlotter {

class QtResources {
public:
  QtResources(QwtPlot* source, QVBoxLayout* vbox);

  FunctionPlot* getFunctionPlot1();
  FunctionPlot* getFunctionPlot2();
  FunctionWithIntervalsPlot* getFunctionPlot3();

  void replot();
  void updateZoomerBase();

private:
  void initGrid();
  void initLegend();
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
  FunctionPlot Plot2_;
  FunctionWithIntervalsPlot Plot3_;
};

} // namespace NSQwtPlotter

} // namespace NSApplication

#endif // QRESOURCES_H
