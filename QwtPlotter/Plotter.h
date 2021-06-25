#ifndef PLOTTER_H
#define PLOTTER_H

#include "PlotterImpl.h"
#include "QwtPlotterWindow.h"
#include "Types.h"

#include <memory>

namespace NSApplication {

namespace NSQwtPlotter {

// namespace NSDetail {

// class PlotterImpl;

//} // namespace NSDetail

class Plotter {
public:
  explicit Plotter(MainWindow* main_window);

  DataRefHolder::CObserver* getDataInput();
  TextHolder::CObserver* getTextInput();

  void subscribeCheckboxState(CheckboxState::CObserver* obs);

private:
  std::unique_ptr<NSDetail::PlotterImpl> Impl_;
};

} // namespace NSQwtPlotter

} // namespace NSApplication

#endif // PLOTTER_H
