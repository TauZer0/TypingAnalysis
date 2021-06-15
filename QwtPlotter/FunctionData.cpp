#include "FunctionData.h"

namespace NSApplication::NSQwtPlotter {

FunctionData::FunctionData(double begin, double end, double step,
                           FunctionPtr function, const std::string& name,
                           const QColor& color)
    : color_(color), function_(function), name_(name) {
  curve_data_.generate(begin, end, step, function);
}

const QColor& FunctionData::getColor() const {
  return color_;
}

const CurveData& FunctionData::getCurveData() const {
  return curve_data_;
}

FunctionPtr FunctionData::getFunction() const {
  return function_;
}

const std::string& FunctionData::getName() const {
  return name_;
}

} // namespace NSApplication::NSQwtPlotter
