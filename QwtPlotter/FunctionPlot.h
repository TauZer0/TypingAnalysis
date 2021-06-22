#ifndef FUNCTIONPLOT_H
#define FUNCTIONPLOT_H

#include "CurveData.h"
#include "FunctionData.h"

#include <QCheckBox>
#include <QObject>
#include <QVBoxLayout>

#include <qwt_plot.h>
#include <qwt_plot_curve.h>

namespace NSApplication {

namespace NSQwtPlotter {

class FunctionPlot : public QObject {
  Q_OBJECT

public:
  FunctionPlot(QwtPlot* source, QVBoxLayout* vbox);

  QCheckBox* getCheckbox();
  QwtPlotCurve* getQwtCurve();

  virtual void setData(const FunctionData& function_data);
  void setName(const std::string& name);

  virtual void show();
  virtual void hide();

  template<typename Object, typename Slot>
  void connectToSlot(Object* object, Slot&& slot) {
    connect(&Checkbox_, &QCheckBox::stateChanged, object,
            std::forward<Slot>(slot));
  }

signals:
  void checkboxSignal();

protected:
  void initCheckbox(QVBoxLayout* vbox);
  void initQwtCurve(QwtPlot* source);
  void setQwtCurve(const CurveData& curve_data);

protected:
  QCheckBox Checkbox_;
  QwtPlotCurve QwtCurve_;
};

} // namespace NSQwtPlotter

} // namespace NSApplication

#endif // FUNCTIONPLOT_H
