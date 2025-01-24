#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <math.h>
#include "../QuadraticEquation.h"

using namespace testing;

TEST(QuadraticEquation, solve_no_roots)
{
    ASSERT_TRUE(QuadraticEquation::solve(1, 0, 1).empty());
}

TEST(QuadraticEquation, solve_two_roots)
{
    auto result = QuadraticEquation::solve(1, 0, -1);
    ASSERT_EQ(result.size(), 2);
    ASSERT_DOUBLE_EQ(result[0], 1);
    ASSERT_DOUBLE_EQ(result[1], -1);
}