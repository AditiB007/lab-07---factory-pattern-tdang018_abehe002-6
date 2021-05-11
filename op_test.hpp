#ifndef __OP_TEST_HPP__
#define __OP_TEST_HPP__

#include "gtest/gtest.h"

#include "op.hpp"

TEST(OpTest, OpEvaluateNonZero) {
    Op* test = new Op(8);
    EXPECT_EQ(test->evaluate(), 8);
}

TEST(OpTest, LargeNumbers) {
  Base* test  = new Op(1234);
  EXPECT_DOUBLE_EQ(test->evaluate(), 1234.000000);
  EXPECT_EQ(test->stringify(), "1234.000000");
}

TEST(OpTest, Negatives) {
  Base* test = new Op(-3);
  EXPECT_DOUBLE_EQ(test->evaluate(), -3.000000);
  EXPECT_EQ(test->stringify(), "-3.000000");
}

TEST(OpTest, Zero) {
  Base* test = new Op(0);
  EXPECT_DOUBLE_EQ(test->evaluate(), 0.000000);
  EXPECT_EQ(test->stringify(), "0.000000");
}

#endif //__OP_TEST_HPP__
