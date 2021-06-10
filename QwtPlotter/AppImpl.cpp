#include "AppImpl.h"

namespace NSApplication::NSQwtPlotter {

AppImpl::AppImpl(QtResources* qresources)
    : plotter_(qresources),
      controller_(&plot_maker_)  {

    plot_maker_.SubscribeText(plotter_.GetTextInput());
    plot_maker_.SubscribePlots(plotter_.GetPlotsInput());
    plotter_.SubscribeFlags(controller_.GetBoolsInput());
}

}  // namespace NSApplication::NSQwtPlotter
