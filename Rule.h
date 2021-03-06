#pragma once
#include "query.h"
#include "rule.h"
#include "schema.h"

using namespace std;

class Rule {
private:
  string conclusionName;
  vector<query> premises;
  schema conclusion;
public:
  Rule(rule toConstruct);
  string toStr();
  int size() const { return premises.size(); }
  query premiseAt(int i) const { return premises.at(i); }
  string name() { return conclusionName; }
  schema Conclusion() { return conclusion; }
  bool causes(const Rule& toCompare);
};
