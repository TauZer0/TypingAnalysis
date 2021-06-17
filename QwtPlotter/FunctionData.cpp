#include "FunctionData.h"

namespace NSApplication::NSQwtPlotter {

FunctionData::FunctionData(double begin, double end, double step,
                           FunctionPtr function, const QColor& color)
    : Color_(color), Function_(function) {
  CurveData_.generate(begin, end, step, function);
}

const QColor& FunctionData::getColor() const {
  return Color_;
}

const CurveData& FunctionData::getCurveData() const {
  return CurveData_;
}

FunctionPtr FunctionData::getFunction() const {
  return Function_;
}

} // namespace NSApplication::NSQwtPlotter
