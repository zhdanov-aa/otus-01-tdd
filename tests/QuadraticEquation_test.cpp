#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "../QuadraticEquation.h"

using namespace testing;

TEST(QuadraticEquation, solve_no_roots)
{
    ASSERT_TRUE(QuadraticEquation::solve(1, 0, 1).empty());
}