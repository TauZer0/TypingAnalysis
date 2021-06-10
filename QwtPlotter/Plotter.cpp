#include "Plotter.h"

namespace NSApplication::NSQwtPlotter {

template<typename T>
using OptionalRef = std::optional<std::reference_wrapper<const T>>;

template<typename T>
void noop(OptionalRef<T>) {
}

void processData(OptionalRef<DataOpt>& function_data, QtResources* qt_resources) {
    if (function_data.value().get().has_value()) {
        qt_resources->setFunctionPlot1(function_data.value().get().value());
        qt_resources->getFunctionPlot1().getQwtCurve()->show();
    } else {
        qt_resources->getFunctionPlot1().getQwtCurve()->hide();
    }
    qt_resources->replot();
    qt_resources->updateZoomerBase();
}

Plotter::Plotter(QtResources* qt_resources)
    : qt_resources_(qt_resources),
      observer_plot_(
          [qt_resources](OptionalRef<DataOpt> function_data) {
              processData(function_data, qt_resources);
          },
          [qt_resources](OptionalRef<DataOpt> function_data) {
              processData(function_data, qt_resources);
          },
          noop<DataOpt>
      ),
      observer_text_(noop<Text>, noop<Text>, noop<Text>) {
    qt_resources_->getFunctionPlot1().connectToSlot(this, &Plotter::processCheckbox1);
}

CObserverDataOpt* Plotter::getPlotInput() {
    return &observer_plot_;
}

CObserverText* Plotter::getTextInput() {
    return &observer_text_;
}

void Plotter::subscribeFlag(CObserverFlag* obs) {
    show_.subscribe(obs);
}

void Plotter::processCheckbox1() {
    QCheckBox* checkbox = static_cast<QCheckBox*>(sender());

    if (checkbox->isChecked()) {
        show_.set(true);
    } else {
        show_.set(false);
    }
}

}  // namespace NSApplication::NSQwtPlotter
