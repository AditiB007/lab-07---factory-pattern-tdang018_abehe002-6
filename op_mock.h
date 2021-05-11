#ifndef __OP_MOCK_H__
#define __OP_MOCK_H__

#include <string>

class Op_Mock : public Base {
  public:
    Op_Mock() {}
    ~Op_Mock() {}

    double evaluate() { // parameters: 3
      return 3.000000;
    }
    
    std::string stringify() {
      return "3.000000";
    }
};

#endif // __OP_MOCK_H__
