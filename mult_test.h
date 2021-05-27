#ifndef __MULT_TEST_H__
#define __MULT_TEST_H__

#include "gtest/gtest.h"

#include "lab3_includes.h"

TEST(MultTest, ThreeTimesTwo) {
  Base* three = new Op(3);
  Base* two = new Op(2);
  Mult* mult = new Mult(three, two);
  EXPECT_DOUBLE_EQ(mult->evaluate(), 6.000000);
  EXPECT_EQ(mult->stringify(), "(3.000000 * 2.000000)");
}

TEST(MultTest, LargeNumbers) {
  Base* large1 = new Op(1234);
  Base* large2 = new Op(5678);
  Mult* mult = new Mult(large1, large2);
  EXPECT_DOUBLE_EQ(mult->evaluate(), 7006652.000000);
  EXPECT_EQ(mult->stringify(), "(1234.000000 * 5678.000000)");
}

TEST(MultTest, Negatives) {
  Base* negative1 = new Op(-3);
  Base* negative2 = new Op(-2);
  Mult* mult = new Mult(negative1, negative2);
  EXPECT_DOUBLE_EQ(mult->evaluate(), 6.000000);
  EXPECT_EQ(mult->stringify(), "(-3.000000 * -2.000000)");
}

TEST(MultTest, Zero) {
  Base* number = new Op(69);
  Base* zero = new Op(0);
  Mult* mult = new Mult(number, zero);
  EXPECT_DOUBLE_EQ(mult->evaluate(), 0.000000);
  EXPECT_EQ(mult->stringify(), "(69.000000 * 0.000000)");
}

TEST(MultTest, Op_Mock) {
  Base* mock = new Op_Mock(); // 3
  Base* mult = new Mult(mock, mock);
  EXPECT_DOUBLE_EQ(mult->evaluate(), 9.000000);
  EXPECT_EQ(mult->stringify(), "(3.000000 * 3.000000)");
}

TEST(MultTest, Add_Mock) {
  Base* mock = new Add_Mock(); // 3 + 2
  Base* number = new Op(4);
  Base* mult = new Mult(mock, number); // (3 + 2) * 4
  EXPECT_DOUBLE_EQ(mult->evaluate(), 20.000000);
  EXPECT_EQ(mult->stringify(), "((3.000000 + 2.000000) * 4.000000)");
}

TEST(MultTest, Rand_Mock) {
  Base* mock = new Rand_Mock(); // 123
  Base* number = new Op(4);
  Base* mult = new Mult(mock, number); // (123 * 4)
  EXPECT_DOUBLE_EQ(mult->evaluate(), 492.000000);
  EXPECT_EQ(mult->stringify(), "(123.000000 * 4.000000)");
}

TEST(MultTest, Sub_Mock) {
  Base* mock = new Sub_Mock(); // 3 - 2
  Base* number = new Op(4);
  Base* mult = new Mult(mock, number); // ((3 - 2) * 4)
  EXPECT_DOUBLE_EQ(mult->evaluate(), 4.000000);
  EXPECT_EQ(mult->stringify(), "((3.000000 - 2.000000) * 4.000000)");
}

TEST(MultTest, Div_Mock) {
  Base* mock = new Div_Mock(); // 3 / 2
  Base* number = new Op(4);
  Base* mult = new Mult(mock, number); // ((3 / 2) * 4)
  EXPECT_DOUBLE_EQ(mult->evaluate(), 6.000000);
  EXPECT_EQ(mult->stringify(), "((3.000000 / 2.000000) * 4.000000)");
}

TEST(MultTest, Pow_Mock) {
  Base* mock = new Pow_Mock(); // 3 ** 2
  Base* number = new Op(4);
  Base* mult = new Mult(mock, number); // ((3 ** 2) * 4)
  EXPECT_DOUBLE_EQ(mult->evaluate(), 36.000000);
  EXPECT_EQ(mult->stringify(), "((3.000000 ** 2.000000) * 4.000000)");
}
 
#endif // __MULT_TEST_H__
