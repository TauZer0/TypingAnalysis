#ifndef PLOTTER_H
#define PLOTTER_H

#include "PlotMaker.h"

#include <qwt_plot.h>
#include <qwt_plot_curve.h>

#include <QCheckBox>
#include <QObject>

#include <string>

#include "QtResources.h"

namespace NSApplication::NSQwtPlotter {

class Plotter : public QObject {
public:
  Plotter(QtResources* qt_resources);

  CObserverRefHolder* getPlotInput();
  CObserverText* getTextInput();

  void subscribeFlag(CObserverFlags* obs);

public slots:
  void processCheckbox1();
  void processCheckbox2();

  // private:
  //    static void processData(QtResources* qt_resources);

private:
  QtResources* qt_resources_{nullptr};
  bool suppressor_{false};

  CObserverRefHolder observer_plot_;
  CObserverText observer_text_;
  Flags visible_plots_{true, true};
  CObservableFlags flags_output_;
};

} // namespace NSApplication::NSQwtPlotter

#endif // PLOTTER_H
