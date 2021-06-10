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
    void SubscribePlots(CObserverPlot* obs);
    void SubscribeText(CObserverText* obs);
    void ControlPlot(bool flag1, bool flag2);

private:
    FunctionData data1_;
    //CurveData data2_;
    CObservablePlot data_port_;

    std::string name1_;
    std::string name2_;
    CObservableText text_port_;

    bool suppressor_{false};
};

}  // namespace NSApplication::NSQwtPlotter

#endif // PLOTMAKER_H
