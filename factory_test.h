#ifndef __FACTORY_TEST_H__
#define __FACTORY_TEST_H__

#include "gtest/gtest.h"

#include "factory.h"
//#include "scan.h"

using namespace std;

TEST(FactoryTest, Add_2_3) {
  //Factory* test = new Factory();
  //Base* tree;

  //char* test_val[1]; test_val[0] = "./calculator"; test_val[1] = "2+3";
  char* c[] = {"./calculator", "2+3"};
  Factory* test = new Factory(2, c);
  //string outputS = factory->getString();
  
  string outputS = test->getString();
  double outputD = test->getDouble();

  EXPECT_EQ("(2.000000 + 3.000000)", outputS);
 // EXPECT_EQ(outputD, 3.0000000);
}
/*
TEST(FactoryTest, Sub) {
  string input = "3-2";
  Factory* test = new Factory();
  string outputS = test.stringify();
  double outputD = test.evaluate();
  EXPECT_EQ(outputS, "3-2");
  EXPECT_EQ(outputD, 1.0000000); 
}

TEST(FactoryTest, Mult) {
  string input = "4*5"
  Factory* test = new Factory();
  string outputS = test.stringify();
  double outputD = test.evaluate();
  EXPECT_EQ(outputS, "4*5");
  EXPECT_EQ(outputD, 20.0000000);
}

TEST(FactoryTest, Div) {
  string input = "12/6"
  Factory* test = new Factory();
  string outputS = test.stringify();
  double outputD = test.evaluate();
  EXPECT_EQ(outputS, "12/6");
  EXPECT_EQ(outputD, 2.0000000);
}

TEST(FactoryTest, Pow) {
  string input = "7**2"
  Factory* test = new Factory();
  string outputS = test.stringify();
  double outputD = test.evaluate();
  EXPECT_EQ(outputS, "7**2");
  EXPECT_EQ(outputD, 49.0000000);
}
*/
#endif //__FACTORY_TEST_H__
