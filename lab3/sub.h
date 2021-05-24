#ifndef __SUB_HPP__
#define __SUB_HPP__

#include "op.hpp"

class Sub: public Base {
  public:

    Base* b1;
    Base* b2;

    Sub(Base* a, Base* b) {
      b1 = a;
      b2 = b;
    }

    ~Sub() {
      delete b1;
      delete b2;
    }

    double evaluate() {
      return b1->evaluate() - b2->evaluate();
    }

    std::string stringify() {
      return "(" + b1->stringify() + " - " + b2->stringify() + ")";
    }
};

#endif // __Sub_HPP__

