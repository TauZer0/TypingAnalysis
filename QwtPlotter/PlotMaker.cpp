#include "PlotMaker.h"

#include "FunctionTable.h"

namespace NSApplication::NSQwtPlotter {

static FunctionTable function_table;

static constexpr double kBegin = 0.0;
static constexpr double kEnd = 5.0;
static constexpr double kStep = 0.001;

PlotMaker::PlotMaker()
    : data1_(kBegin, kEnd, kStep, function_table["sin"], "sin(x)", Qt::red) {
}

void PlotMaker::subscribePlot(CObserverDataOpt* obs) {
    assert(obs != nullptr);
    data_port_.subscribe(obs);
}

void PlotMaker::subscribeText(CObserverText* obs) {
    assert(obs != nullptr);
    text_port_.subscribe(obs);
}

void PlotMaker::controlPlot(bool show_plot1) {
    if (suppressor_) {
        return;
    }

    suppressor_ = true;
    std::optional<DataRef> plot1;
    if (show_plot1) {
        plot1.emplace(std::ref(data1_));
    } else {
        plot1.reset();
    }
    data_port_.set(std::move(plot1));
    suppressor_ = false;
}

}  // namespace NSApplication::NSQwtPlotter
