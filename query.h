#pragma once
#include "predicate.h"
#include "Tuple.h"
#include <vector>
#include <string>
#include <map>

using namespace std;

class query {
private:
  vector<string> params;
  vector<string> unique;
  string name;
  void setUnique();
  bool alreadyUnique(string tofind);
  bool matches(map<string,string> &paramsToConst, Tuple fact);
public:
  query() {}
  query(predicate q);
  string toStr();
  string eval(Tuple fact);
  string Name() { return name; }
};
