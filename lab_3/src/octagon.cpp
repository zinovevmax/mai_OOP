#include "../include/octagon.h"
#include <cmath>

Octagon::Octagon(double sideLength) : sideLength(sideLength) {}

std::pair<double, double> Octagon::getGeometricCenter() const {
    return {0.0, 0.0}; // Геометрический центр восьмиугольника - центр
}

void Octagon::print(std::ostream& os) const {
    os << "Octagon with side length: " << sideLength;
}

void Octagon::read(std::istream& is) {
    is >> sideLength;
}

Octagon::operator double() const {
    return 2 * (1 + std::sqrt(2)) * std::pow(sideLength, 2);
}
