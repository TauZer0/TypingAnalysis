#ifndef TYPES_H
#define TYPES_H

#include "FunctionData.h"
#include "Library/Observer/Observer.h"

namespace NSApplication::NSQwtPlotter {

using FunctionDataRef = std::reference_wrapper<FunctionData>;
using Plot = std::optional<FunctionDataRef>;
using CObservablePlot = NSLibrary::CObservableData<Plot>;
using CObserverPlot = NSLibrary::CObserver<Plot>;

using StringRef = std::reference_wrapper<std::string>;
using Text = std::optional<StringRef>;
using CObservableText = NSLibrary::CObservableData<Text>;
using CObserverText = NSLibrary::CObserver<Text>;

using CObservableFlag = NSLibrary::CObservableData<bool>;
using CObserverFlag = NSLibrary::CObserver<bool>;

}  // namespace NSApplication::NSQwtPlotter

#endif // TYPES_H
