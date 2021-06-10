#ifndef APPIMPL_H
#define APPIMPL_H

#include "Controller.h"
#include "Plotter.h"
#include "PlotMaker.h"
#include "QtResources.h"

namespace NSApplication::NSQwtPlotter {

class AppImpl {
public:
    explicit AppImpl(QtResources* qresources);

private:
    Plotter plotter_;
    PlotMaker plot_maker_;
    Controller controller_;
};

}  // namespace NSApplication::NSQwtPlotter

#endif // APPIMPL_H
