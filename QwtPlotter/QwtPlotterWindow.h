#ifndef QWTPLOTTERWINDOW_H
#define QWTPLOTTERWINDOW_H

#include "QtResources.h"

#include <QMainWindow>
#include <QVBoxLayout>

QT_BEGIN_NAMESPACE
namespace Ui {

class QwtPlotterWindow;

}
QT_END_NAMESPACE

namespace NSApplication::NSQwtPlotter {

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

    QtResources* GetQResources();

signals:
    void PlotChanged();

protected:
   QVBoxLayout* get_box_source();
   QwtPlot* get_plotter_source();

private:
    Ui::QwtPlotterWindow* ui_;
    std::optional<QtResources> qresources_;
};

}  // namespace NSApplication::NSQwtPlotter

#endif // QWTPLOTTERWINDOW_H
