#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <math.h>
#include "../QuadraticEquation.h"

using namespace testing;

const double epsilon = 0.0000001;

TEST(QuadraticEquation, solve_no_roots)
{
    ASSERT_TRUE(QuadraticEquation::solve(1, 0, 1).empty());
}

TEST(QuadraticEquation, solve_two_roots)
{
    auto result = QuadraticEquation::solve(1, 0, -1);
    ASSERT_TRUE(result.size() == 2);
    ASSERT_TRUE(abs(result[0] - 1) < epsilon);
    ASSERT_TRUE(abs(result[1] + 1) < epsilon);
}