#include <iostream>
#include <vector>
#include "../include/figure.h"
#include "../include/hexagon.h"
#include "../include/octagon.h"
#include "../include/triangle.h"

int main() {
    std::vector<Figure*> figures;

    figures.push_back(new Hexagon(1.0));
    figures.push_back(new Octagon(1.0));
    figures.push_back(new Triangle(1.0));

    for (const auto& figure : figures) {
        std::cout << "Geometric center: " << figure->getGeometricCenter().first << ", " << figure->getGeometricCenter().second << std::endl;
        std::cout << "Area: " << static_cast<double>(*figure) << std::endl;
    }

    double totalArea = 0.0;
    for (const auto& figure : figures) {
        totalArea += static_cast<double>(*figure);
    }
    std::cout << "Total area: " << totalArea << std::endl;

    for (auto& figure : figures) {
        delete figure;
    }

    return 0;
}
