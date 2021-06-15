#ifndef FUNCTIONPLOT_H
#define FUNCTIONPLOT_H

#include "CurveData.h"
#include "FunctionData.h"

#include <QCheckBox>
#include <QObject>
#include <QVBoxLayout>

#include <qwt_plot.h>
#include <qwt_plot_curve.h>

namespace NSApplication::NSQwtPlotter {

class FunctionPlot : public QObject {
  Q_OBJECT

public:
  FunctionPlot(QwtPlot* source, QVBoxLayout* vbox);
  QCheckBox* getCheckbox();
  QwtPlotCurve* getQwtCurve();
  void setFunctionPlot(const FunctionData& function_data);

  virtual void show();
  virtual void hide();

  template<typename Object, typename Slot>
  void connectToSlot(Object* object, Slot&& slot) {
    connect(&checkbox_, &QCheckBox::stateChanged, object,
            std::forward<Slot>(slot));
  }

signals:
  void checkboxSignal();

protected:
  void initCheckbox(QVBoxLayout* vbox);
  void initQwtCurve(QwtPlot* source);
  void setQwtCurve(const CurveData& curve_data);

protected:
  QCheckBox checkbox_;
  QwtPlotCurve qwt_curve_;
};

} // namespace NSApplication::NSQwtPlotter

#endif // FUNCTIONPLOT_H
