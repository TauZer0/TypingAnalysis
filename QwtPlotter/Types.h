#ifndef TYPES_H
#define TYPES_H

#include "FunctionData.h"
#include "FunctionWithIntervalsData.h"
#include "Library/Observer/Observer.h"

namespace NSApplication::NSQwtPlotter {

// namespace NSDetail { ?

template<typename T>
using OptionalRef = std::optional<std::reference_wrapper<T>>;

struct RefHolder {
  OptionalRef<FunctionData> optional_ref1_;
  OptionalRef<FunctionWithIntervalsData> optional_ref2_;
};

struct Flags {
  bool plot1_{false};
  bool plot2_{false};
};

//} // namespace NSDetail

// TODO
using CObservableRefHolder = NSLibrary::CObservableData<RefHolder>;
using CObserverRefHolder = NSLibrary::CHotInput<RefHolder>;

using StringRef = std::reference_wrapper<std::string>;
using Text = std::optional<StringRef>;
using CObservableText = NSLibrary::CObservableData<Text>;
using CObserverText = NSLibrary::CObserver<Text>;

using CObservableFlags = NSLibrary::CObservable<Flags>;
using CObserverFlags = NSLibrary::CHotInput<Flags>;

} // namespace NSApplication::NSQwtPlotter

#endif // TYPES_H
