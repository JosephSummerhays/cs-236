#pragma once
#include "charList.h"
#include "token.h"
#include <vector>
using namespace std;

class Scanner {
private:
  vector<Token*> tokenList;
  charList daChars;
  bool getString(string& toReturn);
  bool getSingleComment(string& toReturn);
  bool getMultiComment(string& toReturn);
  void getID(string& toReturn);
  void defaultFunc(char cur);
  void comment(char cur);
public:
  Scanner(string fileName);
  Scanner() {}
  ~Scanner();
  void open(string fileName);
  void scan();
  void print();
  Token* top();
  void pop();
  bool empty() {return tokenList.size() == 0;}
};
