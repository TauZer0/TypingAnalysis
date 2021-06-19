#include "HotkeysInfo.h"
#include "ui_HotkeysInfo.h"

namespace NSApplication::NSQwtPlotter {

HotkeysInfo::HotkeysInfo(QWidget* parent)
    : QDialog(parent), ui(new Ui::HotkeysDialog) {
  ui->setupUi(this);
}

HotkeysInfo::~HotkeysInfo() {
  delete ui;
}

} // namespace NSApplication::NSQwtPlotter
