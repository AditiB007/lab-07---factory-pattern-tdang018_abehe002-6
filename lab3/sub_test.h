#ifndef __SUB_TEST_H__
#define __SUB_TEST_H__

#include "gtest/gtest.h"

#include "sub.h"
#include "op_mock.h"
#include "rand_mock.h"
#include "add_mock.h"
#include "mult_mock.h"
#include "div_mock.h"
#include "pow_mock.h"

TEST(SubTest, ThreeMinusTwo) {
  Base* three = new Op(3);
  Base* two = new Op(2);
  Base* minus = new Sub(three, two);
  EXPECT_DOUBLE_EQ(minus->evaluate(), 1.000000);
  EXPECT_EQ(minus->stringify(), "(3.000000 - 2.000000)");
}

TEST(SubTest, LargeNumbers) {
  Base* large1 = new Op(49723);
  Base* large2 = new Op(8651);
  Base* minus = new Sub(large1, large2);
  EXPECT_DOUBLE_EQ(minus->evaluate(), 41072.000000);
  EXPECT_EQ(minus->stringify(), "(49723.000000 - 8651.000000)");
}

TEST(SubTest, Negatives) {
  Base* negative1 = new Op(-32);
  Base* negative2 = new Op(-5);
  Base* minus = new Sub(negative1, negative2);
  EXPECT_DOUBLE_EQ(minus->evaluate(), -27.000000);
  EXPECT_EQ(minus->stringify(), "(-32.000000 - -5.000000)");
}

TEST(SubTest, Zero) {
  Base* number = new Op(83);
  Base* zero = new Op(0);
  Base* minus = new Sub(number, zero);
  EXPECT_DOUBLE_EQ(minus->evaluate(), 83.000000);
  EXPECT_EQ(minus->stringify(), "(83.000000 - 0.000000)");
}

TEST(SubTest, Op_Mock) {
  Base* mock = new Op_Mock(); // 3
  Base* minus = new Sub(mock, mock);
  EXPECT_DOUBLE_EQ(minus->evaluate(), 0.000000);
  EXPECT_EQ(minus->stringify(), "(3.000000 - 3.000000)");
}

TEST(SubTest, Add_Mock) {
  Base* mock = new Add_Mock(); // 3 + 2
  Base* number = new Op(4);
  Base* minus = new Sub(mock, number); // (3 + 2) - 4
  EXPECT_DOUBLE_EQ(minus->evaluate(), 1.000000);
  EXPECT_EQ(minus->stringify(), "((3.000000 + 2.000000) - 4.000000)");
}

TEST(SubTest, Rand_Mock) {
  Base* mock = new Rand_Mock(); // 123
  Base* number = new Op(4);
  Sub* minus = new Sub(mock, number); // (123 - 4)
  EXPECT_DOUBLE_EQ(minus->evaluate(), 119.000000);
  EXPECT_EQ(minus->stringify(), "(123.000000 - 4.000000)");
}

TEST(SubTest, Mult_Mock) {
  Base* mock = new Mult_Mock(); // 3 * 2
  Base* number = new Op(4);
  Base* minus = new Sub(mock, number); // ((3 * 2) - 4)
  EXPECT_DOUBLE_EQ(minus->evaluate(), 2.000000);
  EXPECT_EQ(minus->stringify(), "((3.000000 * 2.000000) - 4.000000)");
}

TEST(SubTest, Div_Mock) {
  Base* mock = new Div_Mock(); // 3 / 2
  Base* number = new Op(4);
  Sub* minus = new Sub(mock, number); // ((3 / 2) - 4)
  EXPECT_DOUBLE_EQ(minus->evaluate(), -2.500000);
  EXPECT_EQ(minus->stringify(), "((3.000000 / 2.000000) - 4.000000)");
}

TEST(SubTest, Pow_Mock) {
  Base* mock = new Pow_Mock(); // 3 ** 2
  Base* number = new Op(4);
  Base* minus = new Sub(mock, number); // ((3 ** 2) - 4)
  EXPECT_DOUBLE_EQ(minus->evaluate(), 5.000000);
  EXPECT_EQ(minus->stringify(), "((3.000000 ** 2.000000) - 4.000000)");
}

#endif // __SUB_TEST_H__
