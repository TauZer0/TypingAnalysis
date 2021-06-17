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
  FunctionPlot& getFunctionPlot2();
  FunctionWithIntervalsPlot& getFunctionPlot3();

  void showFunctionPlot1(const FunctionData& function_data);
  void showFunctionPlot2(const FunctionData& function_data);
  void showFunctionPlot3(const FunctionWithIntervalsData& function_data);

  void hideFunctionPlot1();
  void hideFunctionPlot2();
  void hideFunctionPlot3();

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
  FunctionPlot Plot2_;
  FunctionWithIntervalsPlot Plot3_;
};

} // namespace NSApplication::NSQwtPlotter

#endif // QRESOURCES_H
