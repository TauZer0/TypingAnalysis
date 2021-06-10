#include "PlotMaker.h"

#include "FunctionTable.h"

namespace NSApplication::NSQwtPlotter {

static FunctionTable function_table;

PlotMaker::PlotMaker() : data1_(0.0, 5.0, 0.001, function_table["sin"], "sin(x)", Qt::red) {
//    double begin = 0.0;
//    double end = 5.0;
//    double step = 0.001;

//    data1_.generate(begin, end, step, function_table["sin"]);
//    name1_ = "sin(x)";

//    data2_.generate(begin, end, step, function_table["ln"]);
//    name2_ = "ln(x)";
}

void PlotMaker::SubscribePlots(CObserverPlot* obs) {
    assert(obs != nullptr);
    data_port_.subscribe(obs);
}

void PlotMaker::SubscribeText(CObserverText* obs) {
    assert(obs != nullptr);
    text_port_.subscribe(obs);
}

void PlotMaker::ControlPlot(bool flag1, bool flag2) {
    if (suppressor_) {
        return;
    }

    suppressor_ = true;
    std::optional<FunctionDataRef> plot1;
    if (flag1) {
        plot1.emplace(std::ref(data1_));
    } else {
        plot1.reset();
    }
    data_port_.set(std::move(plot1));
    suppressor_ = false;
}

}  // namespace NSApplication::NSQwtPlotter
