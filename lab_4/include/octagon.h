#ifndef OCTAGON_H
#define OCTAGON_H

#include "figure.h"
#include <cmath>

template <typename T>
class Octagon : public Figure<T> {
public:
    Octagon(T sideLength) : sideLength(sideLength) {}

    std::pair<T, T> getGeometricCenter() const override {
        return {0, 0};
    }

    void print(std::ostream& os) const override {
        os << "Octagon with side length: " << sideLength;
    }

    void read(std::istream& is) override {
        is >> sideLength;
    }

    operator double() const override {
        return 2 * (1 + std::sqrt(2)) * std::pow(sideLength, 2);
    }

private:
    T sideLength;
};

#endif
