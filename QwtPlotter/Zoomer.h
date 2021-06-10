#ifndef ZOOMER_H
#define ZOOMER_H

#include <qwt_plot_zoomer.h>

namespace NSApplication::NSQwtPlotter {

class Zoomer : public QwtPlotZoomer {
 public:
    Zoomer(QWidget* canvas);
    QwtText trackerTextF(const QPointF& position) const;
    void updateBase();

 private:
    static constexpr int k_default_background_alpha_ = 200;
};

}  // namespace NSApplication::NSQwtPlotter

#endif // ZOOMER_H
