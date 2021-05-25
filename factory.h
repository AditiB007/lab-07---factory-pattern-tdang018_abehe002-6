#ifndef __FACTORY_H__
#define __FACTORY_H__

#include "lab3_includes.h"
//#include "parse.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Factory {
private:
    bool validate(char** input, int length) {
      // "You ... can assume there are no parenthesis and spaces ..."
      if(length != 1 || !input) {return false;}
      return true;
    }

    vector<vector<char*>> split(char* str) {
      vector<string> parsing;
      string token = "";
      
      for(int i=0; i<strlen(str); ++i) {
        char check = str[i];
        if(check == '+' || check == '-' || check == '*' || check == '/') {
          parsing.push_back(token);
          token = "";

          if(str[i+1] == '*') {
            ++i;
            token = "**";
            parsing.push_back(token);
            token = "";
          }
          ++i;
          token = "" + check;
          parsing.push_back(token);
          token = "";

          for(int j=i; j<strlen(str); ++j) {
            tokens[1][j] = str[j];
          }
        }
        else {
          token += check;
        }
        if(i == strlen(str) - 1) {
          parsing.push_back(token);
        }
      }
      return parsing;
    }

public:
    Factory() {
      char input[] = "2+3";
      char* test = split(input);
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
