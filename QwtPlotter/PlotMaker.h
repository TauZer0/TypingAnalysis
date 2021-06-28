#ifndef PLOTMAKER_H
#define PLOTMAKER_H

#include "PlotMakerImpl.h"
#include "Types.h"

#include <memory>

namespace NSApplication {

namespace NSQwtPlotter {

// namespace NSDetail {

// class PlotMakerImpl;

//} // namespace NSDetail

class PlotMaker {
  using ControlFunctionSignature = void(const CheckboxState&);

public:
  using ControlFunctionPtr = ControlFunctionSignature*;

public:
  PlotMaker();
  ControlFunctionPtr getControlFunction() const;
  void subscribePlot(DataRefHolder::CObserver* obs);
  void subscribeText(TextHolder::CObserver* obs);

private:
  std::unique_ptr<NSDetail::PlotMakerImpl> Impl_;
};

} // namespace NSQwtPlotter

} // namespace NSApplication

#endif // PLOTMAKER_H
