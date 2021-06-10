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
    Plotter(QtResources* qresources);

    CObserverPlot* GetPlotsInput();
    CObserverText* GetTextInput();

    void SubscribeFlags(CObserverFlag* obs);

public slots:
    void ProcessCheckbox1();

private:
    QtResources* qresources_{nullptr};
    QwtPlot* qwt_plot_{nullptr};
    QwtPlotCurve* curve1_{nullptr};
    QwtPlotCurve* curve2_{nullptr};
    //CObservableCheckBoxes observable_checkboxes_{nullptr, nullptr};

    std::string* plot1_name_{nullptr};
    std::string* plot2_name_{nullptr};
    std::string* title_{nullptr};

    bool suppressor_{false};

    CObserverPlot observer_plots_;
    CObserverText observer_text_;
    CObservableFlag flags_{false};
};

}  // namespace NSApplication::NSQwtPlotter

#endif // PLOTTER_H
