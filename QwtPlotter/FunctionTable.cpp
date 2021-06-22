#include "FunctionTable.h"

namespace NSApplication::NSQwtPlotter {

FunctionTable::FunctionTable() {
  FunctionMap_ = {
      {"sin", sin}, {"cos", cos}, {"e", exp},
      {"ln", log},  {"tg", tan},  {"sqrt", sqrt},
  };
}

FunctionPtr FunctionTable::operator[](const FunctionName& name) const {
  return FunctionMap_.at(name);
}

FunctionPtr FunctionTable::operator[](FunctionName&& name) const {
  return FunctionMap_.at(name);
}

} // namespace NSApplication::NSQwtPlotter
