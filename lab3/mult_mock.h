#ifndef __MULT_MOCK_H__
#define __MULT_MOCK_H__

#include <string>

class Mult_Mock : public Base {
  public:
    Mult_Mock() {}
    ~Mult_Mock() {}

    double evaluate() { // parameters: 3, 2
      return 6.000000;
    }
    
    std::string stringify() {
      return "(3.000000 * 2.000000)";
    }
};

#endif // __MULT_MOCK_H__
