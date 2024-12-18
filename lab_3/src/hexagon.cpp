#include "../include/hexagon.h"
#include <cmath>

Hexagon::Hexagon(double sideLength) : sideLength(sideLength) {}

Hexagon::Hexagon(const Hexagon& other) : sideLength(other.sideLength) {}

Hexagon& Hexagon::operator=(const Hexagon& other) {
    if (this != &other) {
        sideLength = other.sideLength;
    }
    return *this;
}

std::pair<double, double> Hexagon::getGeometricCenter() const {
    return {0.0, 0.0};
}

void Hexagon::print(std::ostream& os) const {
    os << "Hexagon with side length: " << sideLength;
}

void Hexagon::read(std::istream& is) {
    is >> sideLength;
}

Hexagon::operator double() const {
    return (3 * std::sqrt(3) / 2) * std::pow(sideLength, 2);
}
