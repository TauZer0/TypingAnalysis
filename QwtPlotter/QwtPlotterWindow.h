#ifndef QWTPLOTTERWINDOW_H
#define QWTPLOTTERWINDOW_H

#include "HotkeysInfo.h"
#include "QtResources.h"

#include <QMainWindow>
#include <QVBoxLayout>

QT_BEGIN_NAMESPACE
namespace Ui {

class QwtPlotterWindow;

}
QT_END_NAMESPACE

namespace NSApplication {

namespace NSQwtPlotter {

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
  HotkeysInfo HotkeysInfo_;
  Ui::QwtPlotterWindow* Ui_;
  std::unique_ptr<QtResources> QtResources_;
};

} // namespace NSQwtPlotter

} // namespace NSApplication

#endif // QWTPLOTTERWINDOW_H
