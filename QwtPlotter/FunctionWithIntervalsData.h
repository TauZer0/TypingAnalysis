#ifndef FUNCTIONWITHINTERVALSDATA_H
#define FUNCTIONWITHINTERVALSDATA_H

#include "FunctionData.h"

namespace NSApplication::NSQwtPlotter {

class FunctionWithIntervalsData : public FunctionData {
public:
  FunctionWithIntervalsData(double begin, double end, double step,
                            FunctionPtr function, const std::string& name,
                            const QColor& color);
  void createIntervalData(double begin, double end);
  const CurveData& getIntervalData(size_t i) const;
  size_t getIntervalsDataSize() const;
  int getIntervalsOpacity() const;

private:
  std::vector<CurveData> intervals_data_;
  static constexpr int k_intervals_opacity_ = 50;
};

} // namespace NSApplication::NSQwtPlotter

#endif // FUNCTIONWITHINTERVALSDATA_H
