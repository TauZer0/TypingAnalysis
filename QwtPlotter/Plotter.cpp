#include "Plotter.h"

namespace NSApplication::NSQwtPlotter {

Plotter::Plotter(QtResources* qresources)
    : qresources_(qresources),
      observer_plots_([](std::optional<std::reference_wrapper<const Plot>>) {},
        [this](std::optional<std::reference_wrapper<const Plot>> plot) {
            if (plot.value().get().has_value()) {
                this->qresources_->plot1_.SetFunctionPlot(plot.value().get().value());
                this->qresources_->plot1_.get_qwt_curve()->show();
            } else {
                this->qresources_->plot1_.get_qwt_curve()->hide();
            }
            this->qresources_->source_->replot();
        },
        [](std::optional<std::reference_wrapper<const Plot>>){}),
      observer_text_([](std::optional<std::reference_wrapper<const Text>>){},
        [](std::optional<std::reference_wrapper<const Text>>){},
        [](std::optional<Text>){}) {

    qresources_->GetFunctionPlot1().ConnectToSlot(this, &Plotter::ProcessCheckbox1);

}

CObserverPlot* Plotter::GetPlotsInput() {
    return &observer_plots_;
}

CObserverText* Plotter::GetTextInput() {
    return &observer_text_;
}

void Plotter::SubscribeFlags(CObserverFlag* obs) {
    flags_.subscribe(obs);
}

void Plotter::ProcessCheckbox1() {
    QCheckBox* checkbox = static_cast<QCheckBox*>(sender());

    if (checkbox->isChecked()) {
        flags_.set(true);
    } else {
        flags_.set(false);
    }
}

//void Plotter::Replot() {
//    if (suppressor_) {
//        return;
//    }

//    suppressor_ = true;
//    flags_.notify();
//    suppressor_ = false;
//}

}  // namespace NSApplication::NSQwtPlotter
