#include "gtest/gtest.h"

#include "op_test.hpp"
#include "rand_test.h"
#include "add_test.h"
#include "sub_test.h"
#include "mult_test.h"
#include "div_test.h"
#include "pow_test.h"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

