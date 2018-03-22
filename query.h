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
  string name;
public:
  query() {}
  query(predicate q);
  string toStr();
  string eval(Tuple fact);
  string Name() { return name; }
};
