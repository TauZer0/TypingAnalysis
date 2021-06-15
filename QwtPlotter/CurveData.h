#ifndef CURVEDATA_H
#define CURVEDATA_H

#include "FunctionTable.h"

#include <vector>

namespace NSApplication::NSQwtPlotter {

class CurveData {
public:
  CurveData() = default;
  void addPoint(double x, double y);
  void generate(double begin, double end, double step, FunctionPtr function);

  size_t dataSize() const;
  const double* dataX() const;
  const double* dataY() const;
  const std::vector<double>& getX() const;
  const std::vector<double>& getY() const;

private:
  void generateX(double begin, double end, double step);
  void generateY(FunctionPtr function);

private:
  std::vector<double> X_;
  std::vector<double> Y_;
};

} // namespace NSApplication::NSQwtPlotter

#endif // CURVEDATA_H
