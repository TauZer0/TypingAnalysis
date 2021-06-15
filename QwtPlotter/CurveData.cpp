#include "CurveData.h"

namespace NSApplication::NSQwtPlotter {

void CurveData::addPoint(double x, double y) {
  X_.push_back(x);
  Y_.push_back(y);
}

void CurveData::generate(double begin, double end, double step,
                         FunctionPtr function) {
  generateX(begin, end, step);
  generateY(function);
}

size_t CurveData::dataSize() const {
  return X_.size();
}

const double* CurveData::dataX() const {
  return X_.data();
}

const double* CurveData::dataY() const {
  return Y_.data();
}

const std::vector<double>& CurveData::getX() const {
  return X_;
}

const std::vector<double>& CurveData::getY() const {
  return Y_;
}

void CurveData::generateX(double begin, double end, double step) {
  size_t sample_size = static_cast<size_t>(std::abs(end - begin) / step);
  X_.reserve(sample_size);

  for (size_t i = 0; i < sample_size; ++i) {
    X_.push_back(i * step);
  }
}

void CurveData::generateY(FunctionPtr function) {
  Y_.reserve(X_.size());

  for (const auto& x : X_) {
    Y_.push_back(function(x));
  }
}

} // namespace NSApplication::NSQwtPlotter
