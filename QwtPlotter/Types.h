#ifndef TYPES_H
#define TYPES_H

#include "FunctionData.h"
#include "FunctionWithIntervalsData.h"
#include "Library/Observer/Observer.h"

namespace NSApplication::NSQwtPlotter {

// namespace NSDetail { ?

template<typename T>
using Ref = std::reference_wrapper<T>;

template<typename T>
using OptionalRef = std::optional<Ref<T>>;

struct DataRefHolder {
  OptionalRef<FunctionData> optional_ref1_;
  OptionalRef<FunctionWithIntervalsData> optional_ref2_;
};

struct TextHolder {
  std::string title_;
  std::string plot1_name_;
  std::string plot2_name_;
};

struct Flags {
  bool plot1_{false};
  bool plot2_{false};
};

//} // namespace NSDetail

// TODO
using CObservableRefHolder = NSLibrary::CObservableData<DataRefHolder>;
using CObserverRefHolder = NSLibrary::CHotInput<DataRefHolder>;

using CObservableText = NSLibrary::CObservableData<TextHolder>;
using CObserverText = NSLibrary::CHotInput<TextHolder>;

using CObservableFlags = NSLibrary::CObservable<Flags>;
using CObserverFlags = NSLibrary::CHotInput<Flags>;

} // namespace NSApplication::NSQwtPlotter

#endif // TYPES_H
