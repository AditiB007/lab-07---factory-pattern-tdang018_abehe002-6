#ifndef __POW_MOCK_H__
#define __POW_MOCK_H__

#include <string>

class Pow_Mock : public Base {
  public:
    Pow_Mock() {}
    ~Pow_Mock() {}

    double evaluate() { // parameters: 3, 2
      return 9.000000;
    }
    
    std::string stringify() {
      return "(3.000000 ** 2.000000)";
    }
};

#endif // __POW_MOCK_H__
