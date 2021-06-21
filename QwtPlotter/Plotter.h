#ifndef PLOTTER_H
#define PLOTTER_H

#include "PlotterImpl.h"

#include <memory>

namespace NSApplication::NSQwtPlotter {

class Plotter {
public:
  explicit Plotter(MainWindow* main_window);

  DataRefHolder::CObserver* getDataInput();
  TextHolder::CObserver* getTextInput();

  void subscribeCheckboxState(CheckboxState::CObserver* obs);

private:
  std::unique_ptr<NSDetail::PlotterImpl> Impl_;
};

} // namespace NSApplication::NSQwtPlotter

#endif // PLOTTER_H
