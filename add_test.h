#ifndef __ADD_TEST_H__
#define __ADD_TEST_H__

#include "gtest/gtest.h"

#include "lab3_includes.h"

TEST(AddTest, ThreePlusTwo) {
  Base* three = new Op(3);
  Base* two = new Op(2);
  Add* add = new Add(three, two);
  EXPECT_DOUBLE_EQ(add->evaluate(), 5.000000);
  EXPECT_EQ(add->stringify(), "(3.000000 + 2.000000)");
}

TEST(AddTest, LargeNumbers) {
  Base* large1 = new Op(1234);
  Base* large2 = new Op(5678);
  Add* add = new Add(large1, large2);
  EXPECT_DOUBLE_EQ(add->evaluate(), 6912.000000);
  EXPECT_EQ(add->stringify(), "(1234.000000 + 5678.000000)");
}

TEST(AddTest, Negatives) {
  Base* negative1 = new Op(-3);
  Base* negative2 = new Op(-2);
  Add* add = new Add(negative1, negative2);
  EXPECT_DOUBLE_EQ(add->evaluate(), -5.000000);
  EXPECT_EQ(add->stringify(), "(-3.000000 + -2.000000)");
}

TEST(AddTest, Zero) {
  Base* number = new Op(69);
  Base* zero = new Op(0);
  Add* add = new Add(number, zero);
  EXPECT_DOUBLE_EQ(add->evaluate(), 69.000000);
  EXPECT_EQ(add->stringify(), "(69.000000 + 0.000000)");
}

TEST(AddTest, Op_Mock) {
  Base* mock = new Op_Mock(); // 3
  Base* add = new Add(mock, mock);
  EXPECT_DOUBLE_EQ(add->evaluate(), 6.000000);
  EXPECT_EQ(add->stringify(), "(3.000000 + 3.000000)");
}

TEST(AddTest, Sub_Mock) {
  Base* mock = new Sub_Mock(); // 3 - 2
  Base* number = new Op(4);
  Base* add = new Add(mock, number); // (3 - 2) + 4
  EXPECT_DOUBLE_EQ(add->evaluate(), 5.000000);
  EXPECT_EQ(add->stringify(), "((3.000000 - 2.000000) + 4.000000)");
}

TEST(AddTest, Rand_Mock) {
  Base* mock = new Rand_Mock(); // 123
  Base* number = new Op(4);
  Base* add = new Add(mock, number); // (123 + 4)
  EXPECT_DOUBLE_EQ(add->evaluate(), 127.000000);
  EXPECT_EQ(add->stringify(), "(123.000000 + 4.000000)");
}

TEST(AddTest, Mult_Mock) {
  Base* mock = new Mult_Mock(); // 3 * 2
  Base* number = new Op(4);
  Base* add = new Add(mock, number); // ((3 * 2) + 4)
  EXPECT_DOUBLE_EQ(add->evaluate(), 10.000000);
  EXPECT_EQ(add->stringify(), "((3.000000 * 2.000000) + 4.000000)");
}

TEST(AddTest, Div_Mock) {
  Base* mock = new Div_Mock(); // 3 / 2
  Base* number = new Op(4);
  Base* add = new Add(mock, number); // ((3 / 2) + 4)
  EXPECT_DOUBLE_EQ(add->evaluate(), 5.500000);
  EXPECT_EQ(add->stringify(), "((3.000000 / 2.000000) + 4.000000)");
}

TEST(PowTest, Pow_Mock) {
  Base* mock = new Pow_Mock(); // 3 ** 2
  Base* number = new Op(4);
  Base* add = new Add(mock, number); // ((3 ** 2) + 4)
  EXPECT_DOUBLE_EQ(add->evaluate(), 13.000000);
  EXPECT_EQ(add->stringify(), "((3.000000 ** 2.000000) + 4.000000)");
}
 
#endif // __ADD_TEST_H__
