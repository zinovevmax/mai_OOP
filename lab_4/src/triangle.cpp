#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "../include/figure.h"
#include <cmath>
#include <memory>

template <typename T>
class Triangle : public Figure<T> {
public:
    Triangle(T sideLength) : sideLength(sideLength) {}

    std::pair<T, T> getGeometricCenter() const override {
        return {0, sideLength / 3};
    }

    void print(std::ostream& os) const override {
        os << "Triangle with side length: " << sideLength;
    }

    void read(std::istream& is) override {
        is >> sideLength;
    }

    operator double() const override {
        return (std::sqrt(3) / 4) * std::pow(sideLength, 2);
    }

private:
    T sideLength;
};

#endif
