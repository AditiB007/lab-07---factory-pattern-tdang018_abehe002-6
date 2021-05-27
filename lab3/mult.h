#ifndef __MULT_HPP__
#define __MULT_HPP__

#include "op.hpp"

class Mult: public Base {
  public:

    Base* b1;
    Base* b2;

    Mult(Base* a, Base* b) {
      b1 = a;
      b2 = b;
    }

    ~Mult() {
      delete b1;
      delete b2;
    }

    double evaluate() {
      return b1->evaluate() * b2->evaluate();
    }

    std::string stringify() {
      return "(" + b1->stringify() + " * " + b2->stringify() + ")";
    }
};

#endif // __MULT_HPP__

