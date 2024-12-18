#include <iostream>
#include <vector>
#include <memory>
#include "figure.h"
#include "hexagon.h"
#include "octagon.h"
#include "triangle.h"
#include "array.h"

int main() {
    std::vector<std::shared_ptr<Figure<int>>> figures;

    figures.push_back(std::make_shared<Hexagon<int>>(1));
    figures.push_back(std::make_shared<Octagon<int>>(1));
    figures.push_back(std::make_shared<Triangle<int>>(1));

    for (const auto& figure : figures) {
        std::cout << "Geometric center: (" << figure->getGeometricCenter().first << ", " << figure->getGeometricCenter().second << ")" << std::endl;
        std::cout << "Area: " << static_cast<double>(*figure) << std::endl;
    }

    double totalArea = 0.0;
    for (const auto& figure : figures) {
        totalArea += static_cast<double>(*figure);
    }
    std::cout << "Total area: " << totalArea << std::endl;

    figures.erase(figures.begin() + 1);

    return 0;
}
