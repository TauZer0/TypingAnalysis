#include "QwtPlotterWindow.h"
#include "ui_QwtPlotterWindow.h"

#include <QCheckBox>
#include <QDialog>
#include <QMenuBar>

namespace NSApplication::NSQwtPlotter {

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), Ui_(new Ui::QwtPlotterWindow) {
  Ui_->setupUi(this);
  QtResources_ =
      std::make_unique<QtResources>(getPlotterSource(), getBoxSource());
  QAction* help = menuBar()->addAction("Help");
  connect(help, &QAction::triggered, &HotkeysInfo_, &HotkeysInfo::show);
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
