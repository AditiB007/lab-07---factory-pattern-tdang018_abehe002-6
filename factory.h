#ifndef __FACTORY_H__
#define __FACTORY_H__

#include "lab3_includes.h"

#include <iostream>
#include <vector>
#include <string>
#include <string.h>

using namespace std;

class Factory {
private:

vector<string> parsing;

bool validate(char** input, int length) {
  // "You ... can assume there are no parenthesis and spaces ..."
  if(length != 1 || !input) {return false;}
  return true;
}

vector<string> split(char* str) {
  //vector<string> parsing;
  string token = "";

  for(int i=0; i<strlen(str); ++i) {
    char check = str[i];
//    cout << "check: " << check << endl;
    if(check == '+' || check == '-' || check == '*' || check == '/') {
      if(str[i+1] != '*') {
        token += check;
//        cout << "pushed operator: " << token << endl;
        parsing.push_back(token);
        token = "";
      }
      else { // ** operator detected 
        ++i;
        token = "**";
        parsing.push_back(token);
        token = "";
//        cout << "pushed **: " << token << endl;
      }
          /*
          for(int j=i; j<strlen(str); ++j) {
            tokens[1][j] = str[j];
          }
          */
    }/*
    else if(check == '\0') {
      parsing.push_back(token);
      cout << "null terminator reached: " << check << endl;
      return parsing;
    }*/
    else {
      token += check;
//      cout << "token building: " << token << endl;

      if(str[i+1] == '+' || str[i+1] == '-' || str[i+1] == '*' || str[i+1] == '/') {
        parsing.push_back(token);
        token = "";
      }
    }

    if(i == strlen(str) - 1) {
      parsing.push_back(token);
      return parsing;
    }
  } 
}

public:

Factory() {
  char input[] = "2+3";
  vector<string> test = split(input);
  print();
}
    
~Factory() {
      //for(vector<string>::iterator it = test.begin(); it != test.end()) {
        
      //}
}

void print() {
//  cout << "printing" << endl;
  for(vector<string>::iterator it = parsing.begin(); it != parsing.end(); ++it) {
    cout << *it << " ";
  }
//  cout << "end print()" << endl;
}
    
/*
    Base* parse(char** input, int length) {
      bool valid = false;
      if(validate(input, length)) {
        cout<<"asdf"<<endl;
        return nullptr;
  //      
        for(int i=0; i<length; ++i) {
          std::string str(input[i]); // string of numbers and operators, no spaces
          std::string tokens* = split(str);

          for(int j=0; j<tokens->size(); ++j) { std::cout << tokens[j]; std::cout << std::endl; }

          return nullptr;
        }
      }
      else{
        std::cout << "Error: Invalid input!" << std::endl;
        return nullptr;
//
      }
    }
*/
};

#endif // __FACTORY_H__
