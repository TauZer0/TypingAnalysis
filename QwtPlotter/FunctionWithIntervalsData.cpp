#include "FunctionWithIntervalsData.h"

namespace NSApplication::NSQwtPlotter {

FunctionWithIntervalsData::FunctionWithIntervalsData(double begin, double end,
                                                     double step,
                                                     FunctionPtr function,
                                                     const QColor& color)
    : FunctionData(begin, end, step, function, color) {
}

void FunctionWithIntervalsData::createIntervalData(double begin, double end) {
  CurveData interval_data;

  for (auto it = CurveData_.getX().begin(), jt = CurveData_.getY().begin();
       it < CurveData_.getX().end() && jt < CurveData_.getY().end();
       ++it, ++jt) {
    if (*it < begin) {
      continue;
    } else if (*it > end) {
      break;
    }

    interval_data.addPoint(*it, *jt);
  }

  IntervalsData_.emplace_back(std::move(interval_data));
}

const CurveData& FunctionWithIntervalsData::getIntervalData(size_t i) const {
  return IntervalsData_[i];
}

size_t FunctionWithIntervalsData::getIntervalsDataSize() const {
  return IntervalsData_.size();
}

int FunctionWithIntervalsData::getIntervalsOpacity() const {
  return kIntervalsOpacity_;
}

} // namespace NSApplication::NSQwtPlotter
