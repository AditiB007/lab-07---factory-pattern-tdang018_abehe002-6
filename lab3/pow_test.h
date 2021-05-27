#ifndef __POW_TEST_H__
#define __POW_TEST_H__

#include "gtest/gtest.h"

#include "pow.h"
#include "op_mock.h"
#include "rand_mock.h"
#include "add_mock.h"
#include "mult_mock.h"
#include "div_mock.h"
#include "sub_mock.h"

TEST(PowTest, ThreePowTwo) {
  Base* three = new Op(3);
  Base* two = new Op(2);
  Pow* pow = new Pow(three, two);
  EXPECT_DOUBLE_EQ(pow->evaluate(), 9.000000);
  EXPECT_EQ(pow->stringify(), "(3.000000 ** 2.000000)");
}

TEST(PowTest, LargeNumbers) {
  Base* large1 = new Op(2);
  Base* large2 = new Op(10);
  Pow* pow = new Pow(large1, large2);
  EXPECT_DOUBLE_EQ(pow->evaluate(), 1024.000000);
  EXPECT_EQ(pow->stringify(), "(2.000000 ** 10.000000)");
}

TEST(PowTest, Negatives) {
  Base* negative1 = new Op(-3);
  Base* negative2 = new Op(-2);
  Pow* pow = new Pow(negative1, negative2);
  EXPECT_DOUBLE_EQ(pow->evaluate(), 0.1111111111111111);
  EXPECT_EQ(pow->stringify(), "(-3.000000 ** -2.000000)");
}

TEST(PowTest, Zero) {
  Base* number = new Op(69);
  Base* zero = new Op(0);
  Pow* pow = new Pow(number, zero);
  EXPECT_DOUBLE_EQ(pow->evaluate(), 1.000000);
  EXPECT_EQ(pow->stringify(), "(69.000000 ** 0.000000)");
}

TEST(PowTest, Op_Mock) {
  Base* mock = new Op_Mock(); // 3
  Base* pow = new Pow(mock, mock);
  EXPECT_DOUBLE_EQ(pow->evaluate(), 27.000000);
  EXPECT_EQ(pow->stringify(), "(3.000000 ** 3.000000)");
}

TEST(PowTest, Add_Mock) {
  Base* mock = new Add_Mock(); // 3 + 2
  Base* number = new Op(4);
  Base* pow = new Pow(mock, number); // (3 + 2) ** 4
  EXPECT_DOUBLE_EQ(pow->evaluate(), 625.000000);
  EXPECT_EQ(pow->stringify(), "((3.000000 + 2.000000) ** 4.000000)");
}

TEST(PowTest, Rand_Mock) {
  Base* mock = new Rand_Mock(); // 123
  Base* number = new Op(4);
  Base* pow = new Pow(mock, number); // (123 ** 4)
  EXPECT_DOUBLE_EQ(pow->evaluate(), 228886641);
  EXPECT_EQ(pow->stringify(), "(123.000000 ** 4.000000)");
}

TEST(PowTest, Mult_Mock) {
  Base* mock = new Mult_Mock(); // 3 * 2
  Base* number = new Op(4);
  Base* pow = new Pow(mock, number); // ((3 * 2) ** 4)
  EXPECT_DOUBLE_EQ(pow->evaluate(), 1296.000000);
  EXPECT_EQ(pow->stringify(), "((3.000000 * 2.000000) ** 4.000000)");
}

TEST(PowTest, Div_Mock) {
  Base* mock = new Div_Mock(); // 3 / 2
  Base* number = new Op(4);
  Base* pow = new Pow(mock, number); // ((3 / 2) ** 4)
  EXPECT_DOUBLE_EQ(pow->evaluate(), 5.062500);
  EXPECT_EQ(pow->stringify(), "((3.000000 / 2.000000) ** 4.000000)");
}

TEST(PowTest, Sub_Mock) {
  Base* mock = new Sub_Mock(); // 3 - 2
  Base* number = new Op(4);
  Base* pow = new Pow(mock, number); // ((3 - 2) ** 4)
  EXPECT_DOUBLE_EQ(pow->evaluate(), 1.000000);
  EXPECT_EQ(pow->stringify(), "((3.000000 - 2.000000) ** 4.000000)");
}

#endif // __POW_TEST_H__
