#ifndef PLOTMAKER_H
#define PLOTMAKER_H

#include "PlotMakerImpl.h"

#include <memory>

namespace NSApplication::NSQwtPlotter {

class PlotMaker {
public:
  PlotMaker();
  void controlPlot(const CheckboxState& checkbox_state);
  void subscribePlot(DataRefHolder::CObserver* obs);
  void subscribeText(TextHolder::CObserver* obs);

  NSDetail::PlotMakerImpl* getImpl();

private:
  std::unique_ptr<NSDetail::PlotMakerImpl> Impl_;
};

} // namespace NSApplication::NSQwtPlotter

#endif // PLOTMAKER_H
