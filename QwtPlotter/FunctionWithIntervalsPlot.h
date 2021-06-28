#ifndef FUNCTIONWITHINTERVALSPLOT_H
#define FUNCTIONWITHINTERVALSPLOT_H

#include "FunctionPlot.h"
#include "FunctionWithIntervalsData.h"

namespace NSApplication {

namespace NSQwtPlotter {

class FunctionWithIntervalsPlot : public FunctionPlot {
public:
  FunctionWithIntervalsPlot(QwtPlot* source, QVBoxLayout* vbox);

  const std::vector<std::unique_ptr<QwtPlotCurve>>& getQwtIntervals() const;

  void setData(const FunctionData& function_data) override;

  void show() override;
  void hide() override;

private:
  void initQwtInterval(size_t i);
  void initQwtIntervals();
  void resizeQwtIntervals(size_t n);
  void setQwtInterval(size_t i, const CurveData& interval_data,
                      const QColor& color);
  void setQwtIntervals(const FunctionWithIntervalsData& function_data);

private:
  QwtPlot* Source_{nullptr};
  std::vector<std::unique_ptr<QwtPlotCurve>> QwtIntervals_;
};

} // namespace NSQwtPlotter

} // namespace NSApplication

#endif // FUNCTIONWITHINTERVALSPLOT_H
