#ifndef __RAND_HPP__
#define __RAND_HPP__

#include "op.hpp"
#include <stdlib.h>
#include <time.h>

class Rand: public Base {
  private:
    int value;

  public:

    Rand() {
      srand(time(0));
      value = rand() % 100;
    }
    Rand(int seed) {
      srand(seed);
      value = rand() % 100;
    }

    ~Rand() {
      
    }

    double evaluate() {
      return value;
    }

    std::string stringify() {
      return std::to_string(value);
    }
};

#endif // __MULT_HPP__

