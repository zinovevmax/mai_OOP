#include <gtest/gtest.h>
#include "Thirteen.h"

TEST(ThirteenTest, ConstructorTests) {
    Thirteen t1;
    EXPECT_EQ(t1.toString(), "");

    Thirteen t2(3, 5);
    EXPECT_EQ(t2.toString(), "555");

    Thirteen t3({1, 2, 3});
    EXPECT_EQ(t3.toString(), "321");

    Thirteen t4("1A2B");
    EXPECT_EQ(t4.toString(), "1A2B");
}

TEST(ThirteenTest, AdditionTests) {
    Thirteen t1("1A");
    Thirteen t2("2B");
    Thirteen t3 = t1 + t2;
    EXPECT_EQ(t3.toString(), "49");

    t1 += t2;
    EXPECT_EQ(t1.toString(), "49");
}

TEST(ThirteenTest, SubtractionTests) {
    Thirteen t1("2B");
    Thirteen t2("1A");
    Thirteen t3 = t1 - t2;
    EXPECT_EQ(t3.toString(), "11");

    t1 -= t2;
    EXPECT_EQ(t1.toString(), "11");
}

TEST(ThirteenTest, ComparisonTests) {
    Thirteen t1("1A");
    Thirteen t2("2B");
    Thirteen t3("1A");

    EXPECT_TRUE(t1 < t2);
    EXPECT_TRUE(t2 > t1);
    EXPECT_TRUE(t1 == t3);
    EXPECT_TRUE(t1 != t2);
    EXPECT_TRUE(t1 <= t3);
    EXPECT_TRUE(t2 >= t1);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

