#include "../include/triangle.h"
#include <cmath>

Triangle::Triangle(double sideLength) : sideLength(sideLength) {}

Triangle::Triangle(const Triangle& other) : sideLength(other.sideLength) {}

Triangle& Triangle::operator=(const Triangle& other) {
    if (this != &other) {
        sideLength = other.sideLength;
    }
    return *this;
}

std::pair<double, double> Triangle::getGeometricCenter() const {
    return {0.0, sideLength / 3};
}

void Triangle::print(std::ostream& os) const {
    os << "Triangle with side length: " << sideLength;
}

void Triangle::read(std::istream& is) {
    is >> sideLength;
}

Triangle::operator double() const {
    return (std::sqrt(3) / 4) * std::pow(sideLength, 2);
}
