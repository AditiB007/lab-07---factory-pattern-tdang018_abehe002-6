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

bool validate(int length, char** input) {
  // "You ... can assume there are no parenthesis and spaces ..."
  if(length != 2 || !input) {return false;}
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
//  char input[] = "2+3**4-7";
//  vector<string> test = split(input);
//  print();
}
    
~Factory() {
      //for(vector<string>::iterator it = test.begin(); it != test.end()) {
        
      //}
}

void printParsing() {
//  cout << "printing" << endl;
  for(vector<string>::iterator it = parsing.begin(); it != parsing.end(); ++it) {
    cout << *it << " ";
  }
//  cout << "end print()" << endl;
}

void print(vector<string>::iterator it) {
  cout << *it << " ";
}
    
bool isNum(vector<string>::iterator it) {
  //cout << "test";
  if(it->at(0) >= '0' && it->at(0) <= '9') { return true; }
  //cout << "asd";
  return false;
}

Base* parse(int length, char** input) {
  //cout << "length: " << length << endl;
  bool valid = false;
  if(validate(length, input)) {
    parsing = split(input[1]);
    //print();
    
    Base* left = nullptr;
    Base* parent = nullptr;
    Base* right = nullptr;
    for(vector<string>::iterator it = parsing.begin(); it != parsing.end(); ++it) {
      cout << "it: " << *it << endl;
      if(it == parsing.begin() && !isNum(it)) {
        cout << "Error: Must begin expression with a number!" << endl;
        return nullptr;
      }
      else if(!left) { 
        //cout << stoi(*it) << endl;
        left = new Op(stoi(*it));
        cout << "left: " << left->stringify() << endl;
        delete left;
        //return nullptr;
      }
      else if(left && !parent && !right && !isNum(it)) {
        cout << "parent: " << *it << endl;

        if(isNum(it+1)) { // lookahead to next iteration for right child as number
          right = new Op(stoi(*(it+1)));
          cout << "right: " << right->stringify() << endl;
          delete right;
          //return nullptr;
        }
                
        //parent = makeOperation(left, right);
        //cout << "parent: " << endl;
        //delete parent;
        //++it;
      }
    }
  }
  else{
    std::cout << "Error: Invalid input!" << std::endl;
    return nullptr;
  }
}

};

#endif // __FACTORY_H__
