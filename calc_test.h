#ifndef __CALC_TEST_H__
#define __CALC_TEST_H__

#include "gtest/gtest.h"

#include "lab3_includes.h"
#include "factory.h"
#include 

  Base* three = new Op(3);
  Base* two = new Op(2);
  Mult* mult = new Mult(three, two);
  EXPECT_DOUBLE_EQ(mult->evaluate(), 6.000000);
  EXPECT_EQ(mult->stringify(), "(3.000000 * 2.000000)");
}

