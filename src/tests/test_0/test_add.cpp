#include <gtest/gtest.h>
#include "stage_0/add.h"

TEST(Add, Basic) { EXPECT_EQ(add(2, 3), 5); }
TEST(Add, Large) { EXPECT_EQ(add(1000000000LL, 1000000000LL), 2000000000LL); }
