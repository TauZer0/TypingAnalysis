#include "HotkeysInfo.h"
#include "ui_HotkeysInfo.h"

namespace NSApplication {

namespace NSQwtPlotter {

HotkeysInfo::HotkeysInfo(QWidget* parent)
    : QDialog(parent), ui(new Ui::HotkeysDialog) {
  ui->setupUi(this);
}

HotkeysInfo::~HotkeysInfo() {
  delete ui;
}

} // namespace NSQwtPlotter

} // namespace NSApplication
