#ifndef HEXAGON_H
#define HEXAGON_H

#include "figure.h"
#include <cmath>

template <typename T>
class Hexagon : public Figure<T> {
public:
    Hexagon(T sideLength) : sideLength(sideLength) {}

    std::pair<T, T> getGeometricCenter() const override {
        return {0, 0};
    }

    void print(std::ostream& os) const override {
        os << "Hexagon with side length: " << sideLength;
    }

    void read(std::istream& is) override {
        is >> sideLength;
    }

    operator double() const override {
        return (3 * std::sqrt(3) / 2) * std::pow(sideLength, 2);
    }

private:
    T sideLength;
};

#endif
