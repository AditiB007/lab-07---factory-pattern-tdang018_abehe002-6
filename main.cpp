#include <iostream>
#include "factory.h"
#include <string.h>
#include <string>
#include <cstring>

using namespace std;

int main(int argc, char** argv) {
///*
    Factory* tree = new Factory();

    for(int i = 0; i < argc; i++) {
      cout << argv[i] << " ";
    }
    cout << endl;

    Base* output = tree->parse(argc, argv);
    if(output) {
      cout << "parsing stringify: " << output->stringify() << endl;
      cout << "parsing evaluate: " << output->evaluate() << endl;
    }
//*/

    //char* test_val[1]; test_val[0] = "./calculator"; test_val[1] = "2+3";
    //string s = "2+3";
    //char char_arr[s.length()+1];
    //strcpy(char_arr, s.c_str());

    /*
    char* c[] = {"./calculator", "2+3"};
    Factory* tree = new Factory(2, c);
    cout << "outputS: " << tree->getString() << endl;
    */
    
    delete tree; 
    return 0;
}
