#ifndef PLOTMAKERIMPL_H
#define PLOTMAKERIMPL_H

#include "Support/Suppressor.h"
#include <QCheckBox>

#include "FunctionData.h"
#include "FunctionWithIntervalsData.h"
#include "Library/Observer/Observer.h"
#include "Types.h"

namespace NSApplication::NSQwtPlotter {

namespace NSDetail {

class PlotMakerImpl {
public:
  PlotMakerImpl();
  void controlPlot(const CheckboxState& checkbox_state);
  void subscribePlot(DataRefHolder::CObserver* obs);
  void subscribeText(TextHolder::CObserver* obs);

private:
  template<typename T>
  static void setRef(OptionalRef<T>& ref_holder, T& data, bool is_visible) {
    if (is_visible) {
      ref_holder.emplace(std::ref(data));
    } else {
      ref_holder.reset();
    }
  }

private:
  FunctionData Data1_;
  FunctionData Data2_;
  FunctionWithIntervalsData Data3_;
  DataRefHolder DataRefs_;
  DataRefHolder::CObservable DataOutput_;

  TextHolder::CObservable TextOutput_;

  NSSupport::Suppressor Suppressor_;
};

} // namespace NSDetail

} // namespace NSApplication::NSQwtPlotter

#endif // PLOTMAKERIMPL_H
