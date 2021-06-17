#ifndef PLOTTER_H
#define PLOTTER_H

#include "PlotMaker.h"
#include "QwtPlotterWindow.h"
#include "Support/Suppressor.h"

#include <qwt_plot.h>
#include <qwt_plot_curve.h>

#include <QCheckBox>
#include <QObject>

#include <string>

#include "QtResources.h"

namespace NSApplication::NSQwtPlotter {

class Plotter : public QObject {
public:
  explicit Plotter(MainWindow* main_window);

  DataRefHolder::CObserver* getDataInput();
  TextHolder::CObserver* getTextInput();

  void subscribeVisibilityFlags(VisibilityFlags::CObserver* obs);

public slots:
  void processCheckbox1();
  void processCheckbox2();
  void processCheckbox3();

private:
  void processCheckboxImpl(QCheckBox* checkbox, bool& is_visible);

private:
  MainWindow* MainWindow_{nullptr};
  QtResources* QtResources_{nullptr};
  NSSupport::Suppressor Suppressor_;

  DataRefHolder::CObserver DataInput_;
  TextHolder::CObserver TextInput_;

  VisibilityFlags VisibilityFlags_{true, true, true};
  VisibilityFlags::CObservable VisibilityFlagsOutput_;
};

} // namespace NSApplication::NSQwtPlotter

#endif // PLOTTER_H
