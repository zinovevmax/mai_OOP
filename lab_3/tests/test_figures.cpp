#include <gtest/gtest.h>
#include <cmath> 
#include "../include/hexagon.h"
#include "../include/octagon.h"
#include "../include/triangle.h"

TEST(FiguresTest, Hexagon) {
    Hexagon hexagon(1.0);
    EXPECT_DOUBLE_EQ(static_cast<double>(hexagon), (3 * std::sqrt(3) / 2));
}

TEST(FiguresTest, Octagon) {
    Octagon octagon(1.0);
    EXPECT_DOUBLE_EQ(static_cast<double>(octagon), 2 * (1 + std::sqrt(2)));
}

TEST(FiguresTest, Triangle) {
    Triangle triangle(1.0);
    EXPECT_DOUBLE_EQ(static_cast<double>(triangle), (std::sqrt(3) / 4));
}
