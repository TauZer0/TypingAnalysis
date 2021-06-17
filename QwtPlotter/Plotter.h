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

  CObserverRefHolder* getPlotInput();
  CObserverText* getTextInput();

  void subscribeFlag(CObserverFlags* obs);

public slots:
  void processCheckbox1();
  void processCheckbox2();

  // private:
  //    static void processData(QtResources* qt_resources);
private:
  void processCheckboxImpl(QCheckBox* checkbox, bool& is_visible);

private:
  MainWindow* MainWindow_{nullptr};
  QtResources* QtResources_{nullptr};
  NSSupport::Suppressor Suppressor_;

  CObserverRefHolder ObserverPlot_;
  CObserverText ObserverText_;
  Flags VisiblePlots_{true, true};
  CObservableFlags FlagsOutput_;
};

} // namespace NSApplication::NSQwtPlotter

#endif // PLOTTER_H
