#ifndef __RAND_MOCK_H__
#define __RAND_MOCK_H__

#include <string>

class Rand_Mock: public Base {
  public:
    Rand_Mock() {}
    ~Rand_Mock() {}

    double evaluate() {
      return 123.000000;
    }

    std::string stringify() {
      return "123.000000";
    }
};

#endif // __RAND_MOCK_H__
