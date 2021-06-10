#include "QwtPlotterWindow.h"
#include "ui_QwtPlotterWindow.h"

#include <QCheckBox>

namespace NSApplication::NSQwtPlotter {

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent),
      ui_(new Ui::QwtPlotterWindow) {
    ui_->setupUi(this);
    qt_resources_ = std::make_unique<QtResources>(getPlotterSource(), getBoxSource());
    //QCheckBox* checkbox_1 = (QCheckBox*)ui_->verticalLayout_1->children()[0]; crash
}

MainWindow::~MainWindow() {
    delete ui_;
}

QVBoxLayout* MainWindow::getBoxSource() {
    return ui_->vertical_layout;
}

QwtPlot* MainWindow::getPlotterSource() {
    return ui_->qwt_plot;
}

QtResources* MainWindow::getQtResources() {
    return qt_resources_.get();
}

}  // namespace NSApplication::NSQwtPlotter
