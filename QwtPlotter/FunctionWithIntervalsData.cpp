#include "FunctionWithIntervalsData.h"

namespace NSApplication::NSQwtPlotter {

FunctionWithIntervalsData::FunctionWithIntervalsData(double begin, double end,
                                                     double step,
                                                     FunctionPtr function,
                                                     const std::string& name,
                                                     const QColor& color)
    : FunctionData(begin, end, step, function, name, color) {
}

void FunctionWithIntervalsData::createIntervalData(double begin, double end) {
  CurveData interval_data;

  for (auto it = curve_data_.getX().begin(), jt = curve_data_.getY().begin();
       it < curve_data_.getX().end() && jt < curve_data_.getY().end();
       ++it, ++jt) {
    if (*it < begin) {
      continue;
    } else if (*it > end) {
      break;
    }

    interval_data.addPoint(*it, *jt);
  }

  intervals_data_.emplace_back(std::move(interval_data));
}

const CurveData& FunctionWithIntervalsData::getIntervalData(size_t i) const {
  return intervals_data_[i];
}

size_t FunctionWithIntervalsData::getIntervalsDataSize() const {
  return intervals_data_.size();
}

int FunctionWithIntervalsData::getIntervalsOpacity() const {
  return k_intervals_opacity_;
}

} // namespace NSApplication::NSQwtPlotter
