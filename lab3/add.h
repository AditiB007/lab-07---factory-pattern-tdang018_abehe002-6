#ifndef __ADD_HPP__
#define __ADD_HPP__

#include "op.hpp"

class Add: public Base {
  public:

    Base* b1;
    Base* b2;

    Add(Base* a, Base* b) {
      b1 = a;
      b2 = b;
    }

    ~Add() {
      delete b1;
      delete b2;
    }

    double evaluate() {
      return b1->evaluate() + b2->evaluate();
    }

    std::string stringify() {
      return "(" + b1->stringify() + " + " + b2->stringify() + ")";
    }
};

#endif // __ADD_HPP__

