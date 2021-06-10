#pragma once

#include <cmath>
#include <map>
#include <string>

namespace NSApplication::NSQwtPlotter {

using FunctionSignature = double(double);
using FunctionPtr = FunctionSignature*;
using FunctionName = std::string;

class FunctionTable {
public:
    FunctionTable();
    FunctionPtr operator[](const FunctionName& name);
    FunctionPtr operator[](FunctionName&& name);

private:
    std::map<FunctionName, FunctionPtr> function_map_;
};

}  // namespace NSApplication::NSQwtPlotter
