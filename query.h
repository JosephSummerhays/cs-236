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
  vector<int> toProject;
  string name;
  void setUnique();
  bool alreadyUnique(string tofind);
  bool matches(map<string,string> &paramsToConst, Tuple fact);
public:
  query() {}
  query(predicate q);
  string toStr();
  bool eval(Tuple fact);
  vector<string> getParams() { return unique; }
  vector<int> getProjections() { return toProject; }
  string Name() { return name; }
};
