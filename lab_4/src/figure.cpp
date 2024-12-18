#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
#include <memory>
#include <utility>
#include "../include/point.h"

template <typename T>
class Figure {
public:
    virtual ~Figure() = default;

    virtual std::pair<T, T> getGeometricCenter() const = 0;
    virtual void print(std::ostream& os) const = 0;
    virtual void read(std::istream& is) = 0;
    virtual operator double() const = 0;

    Figure& operator=(const Figure& other) = default;
    Figure& operator=(Figure&& other) noexcept = default;
    bool operator==(const Figure& other) const = default;

    friend std::ostream& operator<<(std::ostream& os, const Figure& figure) {
        figure.print(os);
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Figure& figure) {
        figure.read(is);
        return is;
    }
};

#endif
