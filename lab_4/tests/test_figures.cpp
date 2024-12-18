#include <gtest/gtest.h>
#include "../include/hexagon.h"
#include "../include/octagon.h"
#include "../include/triangle.h"

TEST(FiguresTest, Hexagon) {
    Hexagon<int> hexagon(1);
    EXPECT_DOUBLE_EQ(static_cast<double>(hexagon), (3 * std::sqrt(3) / 2));
}

TEST(FiguresTest, Octagon) {
    Octagon<int> octagon(1);
    EXPECT_DOUBLE_EQ(static_cast<double>(octagon), 2 * (1 + std::sqrt(2)));
}

TEST(FiguresTest, Triangle) {
    Triangle<int> triangle(1);
    EXPECT_DOUBLE_EQ(static_cast<double>(triangle), (std::sqrt(3) / 4));
}
