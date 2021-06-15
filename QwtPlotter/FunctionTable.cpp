#include "FunctionTable.h"

namespace NSApplication::NSQwtPlotter {

FunctionTable::FunctionTable() {
  function_map_ = {
      {"sin", sin}, {"cos", cos}, {"e", exp},
      {"ln", log},  {"tg", tan},  {"sqrt", sqrt},
  };
}

FunctionPtr FunctionTable::operator[](const FunctionName& name) {
  return function_map_[name];
}

FunctionPtr FunctionTable::operator[](FunctionName&& name) {
  return function_map_[name];
}

} // namespace NSApplication::NSQwtPlotter
