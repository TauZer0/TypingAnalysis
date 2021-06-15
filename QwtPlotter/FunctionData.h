#ifndef FUNCTIONDATA_H
#define FUNCTIONDATA_H

#include <QColor>

#include "CurveData.h"

namespace NSApplication::NSQwtPlotter {

class FunctionData {
public:
  FunctionData(double begin, double end, double step, FunctionPtr function,
               const std::string& name, const QColor& color);
  const QColor& getColor() const;
  const CurveData& getCurveData() const;
  FunctionPtr getFunction() const;
  const std::string& getName() const;

protected:
  QColor color_;
  CurveData curve_data_;
  FunctionPtr function_;
  std::string name_;
};

} // namespace NSApplication::NSQwtPlotter

#endif // FUNCTIONDATA_H
