#include <iostream>
#include "factory.h"
#include <string.h>
#include <string>

using namespace std;

int main(int argc, char** argv) {
    Factory* tree = new Factory();
    //tree->parse(argc, argv);
// /*
    for(int i = 0; i < argc; i++) {
      cout << argv[i] << " ";
    }
    cout << endl;
//*/
    Base* output = tree->parse(argc, argv);
    if(output) {
      cout << "parsing stringify: " << output->stringify() << endl;
      //cout << "parsing evaluate: " << output->evaluate() << endl;
    }
    delete tree;

    return 0;
}
