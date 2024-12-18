#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <concepts>

template <typename T>
concept Scalar = std::is_arithmetic_v<T>;

template <Scalar T>
class Point {
public:
    Point(T x, T y) : x(x), y(y) {}

    T getX() const { return x; }
    T getY() const { return y; }

    friend std::ostream& operator<<(std::ostream& os, const Point<T>& point) {
        os << "(" << point.x << ", " << point.y << ")";
        return os;
    }

private:
    T x;
    T y;
};

#endif
