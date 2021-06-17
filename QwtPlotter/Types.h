#ifndef TYPES_H
#define TYPES_H

#include "FunctionData.h"
#include "FunctionWithIntervalsData.h"
#include "Library/Observer/Observer.h"

namespace NSApplication::NSQwtPlotter {

template<typename T>
using Ref = std::reference_wrapper<T>;

template<typename T>
using OptionalRef = std::optional<Ref<T>>;

struct DataRefHolder {
  using CObservable = NSLibrary::CObservableData<DataRefHolder>;
  using CObserver = NSLibrary::CObserverHotStrict<DataRefHolder>;

  OptionalRef<FunctionData> OptionalData1;
  OptionalRef<FunctionData> OptionalData2;
  OptionalRef<FunctionWithIntervalsData> OptionalData3;
};

struct TextHolder {
  using CObservable = NSLibrary::CObservableData<TextHolder>;
  using CObserver = NSLibrary::CHotInput<TextHolder>;

  std::string Title;
  std::string NamePlot1;
  std::string NamePlot2;
  std::string NamePlot3;
};

struct VisibilityFlags {
  using CObservable = NSLibrary::CObservable<VisibilityFlags>;
  using CObserver = NSLibrary::CHotInput<VisibilityFlags>;

  bool Plot1{false};
  bool Plot2{false};
  bool Plot3{false};
};

} // namespace NSApplication::NSQwtPlotter

#endif // TYPES_H
