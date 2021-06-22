#ifndef ZOOMER_H
#define ZOOMER_H

#include <qwt_plot_zoomer.h>

namespace NSApplication {

namespace NSQwtPlotter {

class Zoomer : public QwtPlotZoomer {
public:
  Zoomer(QWidget* canvas);
  QwtText trackerTextF(const QPointF& position) const;
  void updateBase();

private:
  static constexpr int kDefaultBackgroundAlpha_ = 200;
};

} // namespace NSQwtPlotter

} // namespace NSApplication

#endif // ZOOMER_H
