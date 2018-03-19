#pragma once
#include <fstream>
using namespace std;

class charList {
private:
  ifstream file;
  int lineNum;
public:
  charList ();
  charList (string fileName);
  void open(string fileName);
  int getlineNum();
  char get();
  bool isNext(char toCheck);
  bool eof();
  char getPeek();
};
