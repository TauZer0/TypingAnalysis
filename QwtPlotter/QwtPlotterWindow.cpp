#include "QwtPlotterWindow.h"
#include "ui_QwtPlotterWindow.h"

#include <QCheckBox>

namespace NSApplication::NSQwtPlotter {

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent),
      ui_(new Ui::QwtPlotterWindow) {
    ui_->setupUi(this);
    qresources_.emplace(get_plotter_source(), get_box_source());
    //QCheckBox* checkbox_1 = (QCheckBox*)ui_->verticalLayout_1->children()[0]; crash
}

MainWindow::~MainWindow() {
    delete ui_;
}

QVBoxLayout* MainWindow::get_box_source() {
    return ui_->vertical_layout;
}

QwtPlot* MainWindow::get_plotter_source() {
    return ui_->qwt_plot;
}

QtResources* MainWindow::GetQResources() {
    return &qresources_.value();
}

}  // namespace NSApplication::NSQwtPlotter
