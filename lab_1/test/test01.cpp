#include <gtest/gtest.h>
#include "../include/isPerfectSquare.h"

TEST(test_01, basic_test_set)
{
    ASSERT_TRUE(isPerfectSquare(9)==(5, 4));
}

TEST(test_02, basic_test_set)
{
    ASSERT_TRUE(isPerfectSquare(10)==(5, 4));}

TEST(test_03, basic_test_set)
{
    ASSERT_TRUE(isPerfectSquare(30)==(29, 20));
}

TEST(test_04, basic_test_set)
{
    ASSERT_TRUE(isPerfectSquare(9)==(45, 36));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}