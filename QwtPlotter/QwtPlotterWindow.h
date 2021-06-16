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

  QtResources* getQtResources();

protected:
  QVBoxLayout* getBoxSource();
  QwtPlot* getPlotterSource();

private:
  Ui::QwtPlotterWindow* Ui_;
  std::unique_ptr<QtResources> QtResources_;
};

} // namespace NSApplication::NSQwtPlotter

#endif // QWTPLOTTERWINDOW_H
