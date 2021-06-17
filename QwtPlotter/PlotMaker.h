#ifndef PLOTMAKER_H
#define PLOTMAKER_H

#include "Support/Suppressor.h"
#include <QCheckBox>

#include "FunctionData.h"
#include "FunctionWithIntervalsData.h"
#include "Library/Observer/Observer.h"
#include "Types.h"

namespace NSApplication::NSQwtPlotter {

class PlotMaker {
public:
  PlotMaker();
  void controlPlot(bool show_plot1, bool show_plot2);
  void subscribePlot(CObserverRefHolder* obs);
  void subscribeText(CObserverText* obs);

private:
  template<typename T>
  void setRef(OptionalRef<T>& ref_holder, T& data, bool flag) {
    if (flag) {
      ref_holder.emplace(std::ref(data));
    } else {
      ref_holder.reset();
    }
  }

private:
  FunctionData Data1_;
  FunctionWithIntervalsData Data2_;
  DataRefHolder DataRefs_;
  CObservableRefHolder DataPort_;

  CObservableText TextPort_;

  NSSupport::Suppressor Suppressor_;
};

} // namespace NSApplication::NSQwtPlotter

#endif // PLOTMAKER_H
