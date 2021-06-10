#ifndef CURVEDATA_H
#define CURVEDATA_H

#include "FunctionTable.h"

#include <vector>

namespace NSApplication::NSQwtPlotter {

class CurveData {
public:
    CurveData() = default;
    void add_point(double x, double y);
    void generate(double begin, double end, double step, FunctionPtr function);

    size_t data_size() const;
    const double* data_X() const;
    const double* data_Y() const;
    const std::vector<double>& get_X() const;
    const std::vector<double>& get_Y() const;

private:
    void generate_X(double begin, double end, double step);
    void generate_Y(FunctionPtr function);

private:
    std::vector<double> X_;
    std::vector<double> Y_;
};

}  // namespace NSApplication::NSQwtPlotter

#endif // CURVEDATA_H
