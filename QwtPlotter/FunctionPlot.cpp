#include "FunctionPlot.h"

namespace NSApplication::NSQwtPlotter {

FunctionPlot::FunctionPlot(QwtPlot* source, QVBoxLayout* vbox) {
    InitQwtCurve(source);
    InitCheckbox(vbox);
}

QCheckBox* FunctionPlot::get_checkbox() {
    return &checkbox_;
}

QwtPlotCurve* FunctionPlot::get_qwt_curve() {
    return &qwt_curve_;
}

void FunctionPlot::SetFunctionPlot(const FunctionData& function_data) {
    checkbox_.setText(function_data.get_name().data());
    checkbox_.setChecked(true);
    checkbox_.show();

    qwt_curve_.setPen(function_data.get_color());
    qwt_curve_.setTitle(function_data.get_name().data());
    SetQwtCurve(function_data.get_curve_data());
}

void FunctionPlot::process_checkbox() {
//    QCheckBox* checkbox = static_cast<QCheckBox*>(sender());

//    if (checkbox->isChecked()) {
//        qwt_curve_->show();
//    } else {
//        qwt_curve_->hide();
//    }

//    emit plot_changed();
}

void FunctionPlot::InitCheckbox(QVBoxLayout* vbox) {
    vbox->addWidget(&checkbox_);
    checkbox_.show();
}


void FunctionPlot::InitQwtCurve(QwtPlot* source) {
    qwt_curve_.setRenderHint(QwtPlotItem::RenderAntialiased);
    qwt_curve_.setStyle(QwtPlotCurve::Lines);
    qwt_curve_.attach(source);
}

void FunctionPlot::SetQwtCurve(const CurveData& curve_data) {
    qwt_curve_.setRawSamples(curve_data.data_X(), curve_data.data_Y(), curve_data.data_size());
    qwt_curve_.show();
}

}  // namespace NSApplication::NSQwtPlotter
