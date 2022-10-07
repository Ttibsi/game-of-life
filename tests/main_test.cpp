#include "../src/foo.cpp"
#include "gtest/gtest.h"

int add(int x, int y);

TEST(main, add_test) { EXPECT_EQ(add(1, 1), 2); }
