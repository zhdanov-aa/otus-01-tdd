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

TEST(QuadraticEquation, solve_one_root)
{
    auto result = QuadraticEquation::solve(1, 2, 1);
    ASSERT_EQ(result.size(), 1);
    ASSERT_DOUBLE_EQ(result[0], -1);
}

TEST(QuadraticEquation, solve_a_zero_exception)
{
    EXPECT_ANY_THROW(QuadraticEquation::solve(0, 1, 1));
}

TEST(QuadraticEquation, solve_D_less_epsilon)
{
    auto result = QuadraticEquation::solve(1, 2, 0.99999999999);
    ASSERT_EQ(result.size(), 1);
    ASSERT_DOUBLE_EQ(result[0], -1);
}