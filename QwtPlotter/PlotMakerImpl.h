#ifndef PLOTMAKERIMPL_H
#define PLOTMAKERIMPL_H

#include "FunctionData.h"
#include "FunctionWithIntervalsData.h"
#include "Library/Observer/Observer.h"
#include "Support/Suppressor.h"
#include "Types.h"

#include <QCheckBox>

namespace NSApplication {

namespace NSQwtPlotter {

namespace NSDetail {

class PlotMakerImpl {
public:
  PlotMakerImpl();
  void subscribePlot(DataRefHolder::CObserver* obs);
  void subscribeText(TextHolder::CObserver* obs);

  static void controlPlot(const CheckboxState& checkbox_state);

private:
  void controlPlotImpl(const CheckboxState& checkbox_state);

  template<typename T>
  static void setRef(OptionalRef<T>& ref_holder, T& data, bool is_visible) {
    if (is_visible) {
      ref_holder.emplace(std::ref(data));
    } else {
      ref_holder.reset();
    }
  }

private:
  inline static const FunctionTable kFunctionTable_;

  static constexpr double kBegin_ = 0.0;
  static constexpr double kEnd_ = 5.0;
  static constexpr double kStep_ = 0.001;

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

} // namespace NSQwtPlotter

} // namespace NSApplication

#endif // PLOTMAKERIMPL_H
