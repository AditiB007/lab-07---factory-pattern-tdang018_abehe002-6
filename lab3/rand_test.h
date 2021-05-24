#ifndef __RAND_TEST_H__
#define __RAND_TEST_H__

#include "gtest/gtest.h"

#include "rand.h"

TEST(RandTest, NotEqual) {
  Rand* rand1 = new Rand(1);
  Rand* rand2 = new Rand(2);
  EXPECT_NE(rand1->evaluate(), rand2->evaluate());
  EXPECT_NE(rand1->stringify(), rand2->stringify());
}

TEST(RandTest, Equal) {
  Rand* rand1 = new Rand(1);
  Rand* rand2 = new Rand(1);
  EXPECT_EQ(rand1->evaluate(), rand2->evaluate());
  EXPECT_EQ(rand1->stringify(), rand2->stringify());
}
 
#endif // __RAND_TEST_H__
