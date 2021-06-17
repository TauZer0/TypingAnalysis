#include "QwtPlotterWindow.h"
#include "ui_QwtPlotterWindow.h"

#include <QCheckBox>

namespace NSApplication::NSQwtPlotter {

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), Ui_(new Ui::QwtPlotterWindow) {
  Ui_->setupUi(this);
  QtResources_ =
      std::make_unique<QtResources>(getPlotterSource(), getBoxSource());
}

MainWindow::~MainWindow() {
  delete Ui_;
}

QVBoxLayout* MainWindow::getBoxSource() {
  return Ui_->vertical_layout;
}

QwtPlot* MainWindow::getPlotterSource() {
  return Ui_->qwt_plot;
}

QtResources* MainWindow::getQtResources() {
  return QtResources_.get();
}

} // namespace NSApplication::NSQwtPlotter
