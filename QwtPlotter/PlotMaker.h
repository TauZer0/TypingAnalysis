#ifndef PLOTMAKER_H
#define PLOTMAKER_H

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
  FunctionData data1_;
  FunctionWithIntervalsData data2_;
  RefHolder data_refs_;
  CObservableRefHolder data_port_;

  std::string name1_;
  std::string name2_;
  CObservableText text_port_;

  bool suppressor_{false};
};

} // namespace NSApplication::NSQwtPlotter

#endif // PLOTMAKER_H
