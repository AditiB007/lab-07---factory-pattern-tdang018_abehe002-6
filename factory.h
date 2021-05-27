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
bool invalid;

Base* left;
Base* right;
Base* parent;

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
      if(check >= '0' && check <= '9') {
        token += check;
//      cout << "token building: " << token << endl;
      
        if(str[i+1] == '+' || str[i+1] == '-' || str[i+1] == '*' || str[i+1] == '/') {
          parsing.push_back(token);
          token = "";
        }
      }
      else {
        cout << "Error: Unexpected symbol detected in parsing!" << endl;
        invalid = true;
        return parsing;
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
  invalid = false;
  left = right = parent = nullptr;
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

void clear() {
  delete left;
  delete right;
  delete parent;
}

Base* makeOperation(Base* left, Base* right, string op) {
  if(op == "+") { return new Add(left, right); }
  else if(op == "-") { return new Sub(left, right); }
  else if(op == "*") { return new Mult(left, right); }
  else if(op == "/") { return new Div(left, right); }

  cout << "Error: unrecognized operator!" << endl;
  left->~Base();
  delete left;
  right->~Base();
  delete right;

  return nullptr;
}

Base* parse(int length, char** input) {
  //cout << "length: " << length << endl;
  bool valid = false;
  if(validate(length, input)) {
    parsing = split(input[1]);
    if(invalid) { return nullptr; }
    //print();
    
    //Base* left = nullptr;
    //Base* parent = nullptr;
    //Base* right = nullptr;
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
        //delete left;
        //return nullptr;
      }
      else if(left && !parent && !right && !isNum(it)) {
        if((it+1) == parsing.end()) {
          cout << "Error: Invalid number of inputs in expression! There is one too few or too many." << endl;
          clear();
          return nullptr;
        }

        cout << "parent symbol: " << *it << endl;
        
        if(isNum(it+1)) { // lookahead to next iteration for right child as number
          right = new Op(stoi(*(it+1)));
          cout << "right: " << right->stringify() << endl;
          //delete right;
          //return nullptr;
        }
                       
        parent = makeOperation(left, right, *it);
        if(!parent) { return nullptr; }
        else {
          cout << "parent: " << parent->stringify() << endl;
          //delete parent;
          //return nullptr;

          if((it+2) == parsing.end()) {
            cout << "end reached!" << endl;
            return parent;
          }
          else {
            left = parent;
            right = parent = nullptr;
            ++it;
          }
        }
      }
    }
    cout << "Error: Unexpected end of expression reached!" << endl;
    return nullptr;
  }
  else{
    std::cout << "Error: Invalid input!" << std::endl;
    return nullptr;
  }
}

};

#endif // __FACTORY_H__
