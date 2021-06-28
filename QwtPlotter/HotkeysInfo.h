#ifndef QWTPLOTTERHOTKEYSINFO_H
#define QWTPLOTTERHOTKEYSINFO_H

#include <QDialog>

namespace Ui {

class HotkeysDialog;

}

namespace NSApplication {

namespace NSQwtPlotter {

class HotkeysInfo : public QDialog {
  Q_OBJECT

public:
  explicit HotkeysInfo(QWidget* parent = nullptr);
  ~HotkeysInfo();

private:
  Ui::HotkeysDialog* ui;
};

} // namespace NSQwtPlotter

} // namespace NSApplication

#endif // QWTPLOTTERHOTKEYSINFO_H
