#ifndef PLOTMAKER_H
#define PLOTMAKER_H

#include "Types.h"

#include <memory>

namespace NSApplication {

namespace NSQwtPlotter {

namespace NSDetail {

class PlotMakerImpl;

}

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

} // namespace NSQwtPlotter

} // namespace NSApplication

#endif // PLOTMAKER_H
