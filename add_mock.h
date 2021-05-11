#ifndef __ADD_MOCK_H__
#define __ADD_MOCK_H__

#include <string>

class Add_Mock : public Base {
  public:
    Add_Mock() {}
    ~Add_Mock() {}

    double evaluate() { // parameters: 3, 2
      return 5;
    }
    
    std::string stringify() {
      return "(3.000000 + 2.000000)";
    }
};

#endif // __ADD_MOCK_H__
