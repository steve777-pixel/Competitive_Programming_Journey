#include <gtest/gtest.h>
#include "stage_3/knapsack.h"

TEST(Add, Basic) { EXPECT_EQ(subtract(2, 3), -1); }
TEST(Add, Large) { EXPECT_EQ(subtract(1000000000LL, 1000000000LL), 0LL); }