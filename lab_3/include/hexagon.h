#ifndef HEXAGON_H
#define HEXAGON_H

#include "figure.h"

class Hexagon : public Figure {
public:
    Hexagon(double sideLength);
    Hexagon(const Hexagon& other);
    Hexagon(Hexagon&& other) noexcept = default;
    Hexagon& operator=(const Hexagon& other);
    Hexagon& operator=(Hexagon&& other) noexcept = default;

    std::pair<double, double> getGeometricCenter() const override;
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;
    operator double() const override;

private:
    double sideLength;
};

#endif
