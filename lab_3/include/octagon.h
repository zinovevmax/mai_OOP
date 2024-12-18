#ifndef OCTAGON_H
#define OCTAGON_H

#include "figure.h"

class Octagon : public Figure {
public:
    Octagon(double sideLength);
    Octagon(const Octagon& other);
    Octagon(Octagon&& other) noexcept = default;
    Octagon& operator=(const Octagon& other);
    Octagon& operator=(Octagon&& other) noexcept = default;

    std::pair<double, double> getGeometricCenter() const override;
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;
    operator double() const override;

private:
    double sideLength;
};

#endif