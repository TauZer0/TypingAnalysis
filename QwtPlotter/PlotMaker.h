#ifndef PLOTMAKER_H
#define PLOTMAKER_H

#include <QCheckBox>

#include "Library/Observer/Observer.h"
#include "FunctionData.h"
#include "Types.h"

namespace NSApplication::NSQwtPlotter {

class PlotMaker {
public:
    PlotMaker();
    void controlPlot(bool show_plot1);
    void subscribePlot(CObserverDataOpt* obs);
    void subscribeText(CObserverText* obs);

private:
    FunctionData data1_;
    CObservableDataOpt data_port_;

    std::string name1_;
    std::string name2_;
    CObservableText text_port_;

    bool suppressor_{false};
};

}  // namespace NSApplication::NSQwtPlotter

#endif // PLOTMAKER_H
