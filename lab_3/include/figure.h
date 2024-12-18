#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
#include <utility>

class Figure {
public:
    virtual ~Figure() = default;

    virtual std::pair<double, double> getGeometricCenter() const = 0;
    virtual void print(std::ostream& os) const = 0;
    virtual void read(std::istream& is) = 0;
    virtual operator double() const = 0;

    Figure(const Figure&) = delete;
    Figure& operator=(const Figure&) = delete;

    Figure(Figure&&) noexcept = default;
    Figure& operator=(Figure&&) noexcept = default;

    protected:
        Figure() = default;

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
