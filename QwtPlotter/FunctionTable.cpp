#include "FunctionTable.h"

namespace NSApplication::NSQwtPlotter {

FunctionTable::FunctionTable() {
  FunctionMap_ = {
      {"sin", sin}, {"cos", cos}, {"e", exp},
      {"ln", log},  {"tg", tan},  {"sqrt", sqrt},
  };
}

FunctionPtr FunctionTable::operator[](const FunctionName& name) {
  return FunctionMap_[name];
}

FunctionPtr FunctionTable::operator[](FunctionName&& name) {
  return FunctionMap_[name];
}

} // namespace NSApplication::NSQwtPlotter
