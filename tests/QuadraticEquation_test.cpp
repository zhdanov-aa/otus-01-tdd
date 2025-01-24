#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <math.h>
#include "../QuadraticEquation.h"

using namespace testing;

// пункт #3 задания
TEST(QuadraticEquation, CheckNoRoots)
{
    ASSERT_TRUE(QuadraticEquation::solve(1, 0, 1).empty());
}

// пункт #5 задания
TEST(QuadraticEquation, CheckTwoRoots)
{
    auto result = QuadraticEquation::solve(1, 0, -1);
    ASSERT_EQ(result.size(), 2);
    ASSERT_DOUBLE_EQ(result[0], 1);
    ASSERT_DOUBLE_EQ(result[1], -1);
}

// пункт #7 задания
TEST(QuadraticEquation, CheckOneRoot)
{
    auto result = QuadraticEquation::solve(1, 2, 1);
    ASSERT_EQ(result.size(), 1);
    ASSERT_DOUBLE_EQ(result[0], -1);
}

// пункт #9 задания
TEST(QuadraticEquation, CheckAZeroException)
{
    EXPECT_ANY_THROW(QuadraticEquation::solve(0, 1, 1));
}

// пункт #11 задания
TEST(QuadraticEquation, CheckDLessEpsilon)
{
    auto result = QuadraticEquation::solve(1, 2, 0.99999999999);
    ASSERT_EQ(result.size(), 1);
    ASSERT_DOUBLE_EQ(result[0], -1);
}

// пункт #13 задания
TEST(QuadraticEquation, CheckArgsNanInfException)
{
    EXPECT_ANY_THROW(QuadraticEquation::solve(NAN, 3, 1));
    EXPECT_ANY_THROW(QuadraticEquation::solve(INFINITY, 3, 1));
    EXPECT_ANY_THROW(QuadraticEquation::solve(-INFINITY, 3, 1));

    EXPECT_ANY_THROW(QuadraticEquation::solve(1, NAN, 1));
    EXPECT_ANY_THROW(QuadraticEquation::solve(1, INFINITY, 1));
    EXPECT_ANY_THROW(QuadraticEquation::solve(1, -INFINITY, 1));

    EXPECT_ANY_THROW(QuadraticEquation::solve(1, 3, NAN));
    EXPECT_ANY_THROW(QuadraticEquation::solve(1, 3, INFINITY));
    EXPECT_ANY_THROW(QuadraticEquation::solve(1, 3, -INFINITY));
}