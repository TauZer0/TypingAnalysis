#ifndef FUNCTIONPLOT_H
#define FUNCTIONPLOT_H

#include "CurveData.h"
#include "FunctionData.h"

#include <QCheckBox>
#include <QObject>
#include <QVBoxLayout>

#include <qwt_plot.h>
#include <qwt_plot_curve.h>

namespace NSApplication::NSQwtPlotter {

class FunctionPlot : public QObject {
    Q_OBJECT

public:
    FunctionPlot(QwtPlot* source, QVBoxLayout* vbox);
    QCheckBox* get_checkbox();
    QwtPlotCurve* get_qwt_curve();
    void SetFunctionPlot(const FunctionData& function_data);

    template<typename Object, typename Slot>
    void ConnectToSlot(Object* object, Slot&& slot) {
        connect(&checkbox_, &QCheckBox::stateChanged, object, std::forward<Slot>(slot));
    }

signals:
    void CheckboxSignal();

protected:
    void process_checkbox();
    void InitCheckbox(QVBoxLayout* vbox);
    void InitQwtCurve(QwtPlot* source);
    void SetQwtCurve(const CurveData& curve_data);

protected:
    QCheckBox checkbox_;
    QwtPlotCurve qwt_curve_;
};

}  // namespace NSApplication::NSQwtPlotter

#endif // FUNCTIONPLOT_H
