#include <iostream>
#include "factory.h"
#include "lab3_includes.h"

using namespace std;

string stringPrint(int argc, char** argv) {
    Factory* tree = new Factory();
    Base* output = tree->parse(argc, argv);
    if(output) {
      return output->stringify();
    }
}

