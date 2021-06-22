#ifndef PLOTTERIMPL_H
#define PLOTTERIMPL_H

#include "PlotMakerImpl.h"
#include "QwtPlotterWindow.h"
#include "Support/Suppressor.h"

#include <qwt_plot.h>
#include <qwt_plot_curve.h>

#include <QCheckBox>
#include <QObject>

#include <string>

#include "QtResources.h"

namespace NSApplication {

namespace NSQwtPlotter {

namespace NSDetail {

class PlotterImpl : public QObject {
public:
  explicit PlotterImpl(MainWindow* main_window);

  DataRefHolder::CObserver* getDataInput();
  TextHolder::CObserver* getTextInput();

  void subscribeCheckboxState(CheckboxState::CObserver* obs);

public slots:
  void processCheckbox1();
  void processCheckbox2();
  void processCheckbox3();

private:
  void processCheckboxImpl(QCheckBox* checkbox, bool& is_visible);
  void replot(const DataRefHolder& data);
  void setText(const TextHolder& text_data);

  static void setPlot(FunctionPlot& plot, OptionalRef<FunctionData> data);

private:
  MainWindow* MainWindow_{nullptr};
  QtResources* QtResources_{nullptr};
  FunctionPlot* Plot1_{nullptr};
  FunctionPlot* Plot2_{nullptr};
  FunctionWithIntervalsPlot* Plot3_{nullptr};

  NSSupport::Suppressor Suppressor_;

  DataRefHolder::CObserver DataInput_;
  TextHolder::CObserver TextInput_;

  CheckboxState CheckboxState_{true, true, true};
  CheckboxState::CObservable CheckboxStateOutput_;
};

} // namespace NSDetail

} // namespace NSQwtPlotter

} // namespace NSApplication

#endif // PLOTTERIMPL_H
