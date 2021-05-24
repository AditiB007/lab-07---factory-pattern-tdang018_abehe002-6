#ifndef __SUB_MOCK_H__
#define __SUB_MOCK_H__

#include <string>

class Sub_Mock: public Base {
  public:
    Sub_Mock() {}
    ~Sub_Mock() {}

    double evaluate() { // parameters: 3, 2
      return 1.000000;
    }

    std::string stringify() {
      return "(3.000000 - 2.000000)";
    }
};

#endif // __SUB_MOCK_H__
