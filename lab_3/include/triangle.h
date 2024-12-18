#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "figure.h"

class Triangle : public Figure {
public:
    Triangle(double sideLength);
    Triangle(const Triangle& other);
    Triangle(Triangle&& other) noexcept = default;
    Triangle& operator=(const Triangle& other);
    Triangle& operator=(Triangle&& other) noexcept = default;

    std::pair<double, double> getGeometricCenter() const override;
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;
    operator double() const override;

private:
    double sideLength;
};

#endif
