#ifndef FUNCTIONWITHINTERVALSDATA_H
#define FUNCTIONWITHINTERVALSDATA_H

#include "FunctionData.h"

namespace NSApplication {

namespace NSQwtPlotter {

class FunctionWithIntervalsData : public FunctionData {
public:
  FunctionWithIntervalsData(double begin, double end, double step,
                            FunctionPtr function, const QColor& color);
  void createIntervalData(double begin, double end);
  const CurveData& getIntervalData(size_t i) const;
  size_t getIntervalsDataSize() const;
  int getIntervalsOpacity() const;

private:
  static constexpr int kIntervalsOpacity_ = 50;
  std::vector<CurveData> IntervalsData_;
};

} // namespace NSQwtPlotter

} // namespace NSApplication

#endif // FUNCTIONWITHINTERVALSDATA_H
