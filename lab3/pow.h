#ifndef __POW_HPP__
#define __POW_HPP__

#include "op.hpp"

class Pow: public Base {
  public:

    Base* b1;
    Base* b2;

    Pow(Base* a, Base* b) {
      b1 = a;
      b2 = b;
    }

    ~Pow() {
      delete b1;
      delete b2;
    }

    double evaluate() {
      double result = 1;
      double num1 = b1->evaluate();
      double num2 = b2->evaluate();
      if(num2 < 0) {
        num1 = 1/(num1);
        num2 = (num2)/-1;
      }
      for(int i = 0; i < num2; i++) {
        result *= num1;  
      }
      return result;
    }

    std::string stringify() {
      return "(" + b1->stringify() + " ** " + b2->stringify() + ")";
    }
};

#endif // __ADD_HPP__

