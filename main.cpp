#include <iostream>
#include "factory.h"

using namespace std;

int main(int argc, char** argv) {
    Factory* tree = new Factory();

    for(int i = 0; i < argc; i++) {
      cout << argv[i] << " ";
    }
    cout << endl;

    Base* output = tree->parse(argc, argv);

    cout << output->stringify() << " = " << output->evaluate() << endl;
    
    return 0;
}
