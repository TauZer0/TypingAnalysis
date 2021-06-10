#include "Application.h"

#include "ExceptionHandler.h"
#include "QtLoopException.h"
#include "QwtPlotter/QwtApplication.h"

#include <QApplication>

int main(int argc, char* argv[]) {
  namespace NSApp = NSApplication;
  QApplication QAppLoop(argc, argv);
  NSApp::CQtLoopExceptionInit LoopExceptions;

  try {
    //NSApp::CApplication Application;
    NSApp::NSQwtPlotter::QwtApplication QwtApplication;
    QwtApplication.show();
    QAppLoop.exec();
  } catch (...) {
    NSApp::CExceptionHandler React;
  }
  return 0;
}
