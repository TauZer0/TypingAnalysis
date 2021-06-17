#ifndef FUNCTIONWITHINTERVALSDATA_H
#define FUNCTIONWITHINTERVALSDATA_H

#include "FunctionData.h"

namespace NSApplication::NSQwtPlotter {

class FunctionWithIntervalsData : public FunctionData {
public:
  FunctionWithIntervalsData(double begin, double end, double step,
                            FunctionPtr function, const QColor& color);
  void createIntervalData(double begin, double end);
  const CurveData& getIntervalData(size_t i) const;
  size_t getIntervalsDataSize() const;
  int getIntervalsOpacity() const;

private:
  std::vector<CurveData> IntervalsData_;
  static constexpr int kIntervalsOpacity_ = 50;
};

} // namespace NSApplication::NSQwtPlotter

#endif // FUNCTIONWITHINTERVALSDATA_H
