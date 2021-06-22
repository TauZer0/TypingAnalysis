#ifndef FUNCTIONTABLE_H
#define FUNCTIONTABLE_H

#include <cmath>
#include <map>
#include <string>

namespace NSApplication {

namespace NSQwtPlotter {

using FunctionSignature = double(double);
using FunctionPtr = FunctionSignature*;
using FunctionName = std::string;

class FunctionTable {
public:
  FunctionTable();
  FunctionPtr operator[](const FunctionName& name) const;
  FunctionPtr operator[](FunctionName&& name) const;

private:
  std::map<FunctionName, FunctionPtr> FunctionMap_;
};

} // namespace NSQwtPlotter

} // namespace NSApplication

#endif // FUNCTIONTABLE_H
