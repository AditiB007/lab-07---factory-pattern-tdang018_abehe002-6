#ifndef __DIV_MOCK_H__
#define __DIV_MOCK_H__

#include <string>

class Div_Mock: public Base {
  public:
    Div_Mock() {}
    ~Div_Mock() {}

    double evaluate() { // parameters: 3, 2
      return 1.500000;
    }

    std::string stringify() {
      return "(3.000000 / 2.000000)";
    }
};

#endif // __DIV_MOCK_H__
