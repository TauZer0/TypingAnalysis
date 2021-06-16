#include "Zoomer.h"

namespace NSApplication::NSQwtPlotter {

Zoomer::Zoomer(QWidget* canvas) : QwtPlotZoomer(canvas) {
  setTrackerMode(AlwaysOn);
}

QwtText Zoomer::trackerTextF(const QPointF& position) const {
  QColor background(Qt::white);
  background.setAlpha(kDefaultBackgroundAlpha_);
  QwtText text = QwtPlotZoomer::trackerTextF(position);
  text.setBackgroundBrush(QBrush(background));
  return text;
}

void Zoomer::updateBase() {
  setZoomBase(scaleRect());
}

} // namespace NSApplication::NSQwtPlotter
