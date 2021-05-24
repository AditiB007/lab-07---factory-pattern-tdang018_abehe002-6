#ifndef __DIV_TEST_H__
#define __DIV_TEST_H__

#include "gtest/gtest.h"

#include "div.h"
#include "op_mock.h"
#include "rand_mock.h"
#include "add_mock.h"
#include "sub_mock.h"
#include "mult_mock.h"
#include "pow_mock.h"

TEST(DivTest, ThreeDivTwo) {
  Base* three = new Op(3);
  Base* two = new Op(2);
  Base* div = new Div(three, two);
  EXPECT_DOUBLE_EQ(div->evaluate(), 1.500000);
  EXPECT_EQ(div->stringify(), "(3.000000 / 2.000000)");
}

TEST(DivTest, LargeNumbers) {
  Base* large1 = new Op(1234);
  Base* large2 = new Op(5678);
  Base* div = new Div(large1, large2);
  EXPECT_DOUBLE_EQ(div->evaluate(), 0.21733004579077139);
  EXPECT_EQ(div->stringify(), "(1234.000000 / 5678.000000)");
}

TEST(DivTest, Negatives) {
  Base* negative1 = new Op(-3);
  Base* negative2 = new Op(-2);
  Base* div = new Div(negative1, negative2);
  EXPECT_DOUBLE_EQ(div->evaluate(), 1.500000);
  EXPECT_EQ(div->stringify(), "(-3.000000 / -2.000000)");
}

TEST(DivTest, Zero) {
  Base* number = new Op(69);
  Base* zero = new Op(0);
  Base* div = new Div(number, zero);
  EXPECT_THROW(div->evaluate(), std::domain_error);
  EXPECT_EQ(div->stringify(), "(69.000000 / 0.000000)");
}

TEST(DivTest, Op_Mock) {
  Base* mock = new Op_Mock(); // 3
  Base* div = new Div(mock, mock);
  EXPECT_DOUBLE_EQ(div->evaluate(), 1.000000);
  EXPECT_EQ(div->stringify(), "(3.000000 / 3.000000)");
}

TEST(DivTest, Add_Mock) {
  Base* mock = new Add_Mock(); // 3 + 2
  Base* number = new Op(4);
  Base* div = new Div(mock, number); // (3 + 2) / 4
  EXPECT_DOUBLE_EQ(div->evaluate(), 1.250000);
  EXPECT_EQ(div->stringify(), "((3.000000 + 2.000000) / 4.000000)");
}

TEST(DivTest, Rand_Mock) {
  Base* mock = new Rand_Mock(); // 123
  Base* number = new Op(4);
  Base* div = new Div(mock, number); // (123 / 4)
  EXPECT_DOUBLE_EQ(div->evaluate(), 30.750000);
  EXPECT_EQ(div->stringify(), "(123.000000 / 4.000000)");
}

TEST(DivTest, Sub_Mock) {
  Base* mock = new Sub_Mock(); // 3 - 2
  Base* number = new Op(4);
  Base* div = new Div(mock, number); // ((3 - 2) / 4)
  EXPECT_DOUBLE_EQ(div->evaluate(), 0.250000);
  EXPECT_EQ(div->stringify(), "((3.000000 - 2.000000) / 4.000000)");
}

TEST(DivTest, Mult_Mock) {
  Base* mock = new Mult_Mock(); // 3 * 2
  Base* number = new Op(4);
  Base* div = new Div(mock, number); // ((3 * 2) / 4)
  EXPECT_DOUBLE_EQ(div->evaluate(), 1.500000);
  EXPECT_EQ(div->stringify(), "((3.000000 * 2.000000) / 4.000000)");
}

TEST(DivTest, Pow_Mock) {
  Base* mock = new Pow_Mock(); // 3 ** 2
  Base* number = new Op(4);
  Base* div = new Div(mock, number); // ((3 ** 2) / 4)
  EXPECT_DOUBLE_EQ(div->evaluate(), 2.250000);
  EXPECT_EQ(div->stringify(), "((3.000000 ** 2.000000) / 4.000000)");
}
 
#endif // __DIV_TEST_H__
