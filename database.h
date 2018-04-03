#pragma once
#include "dataLog.h"
#include "relation.h"
#include "query.h"
#include "Rule.h"
#include <vector>
#include <iostream>
#include "funcMeasure.h"

using namespace std;

class database {
private:
  vector<relation> relations;
  vector<query> queries;
  vector<Rule> rules;
  relation evaluate(query q);
  string evaluate(int i);
  void getConclusion(int i);
public:
  database(dataLog &data);
  database() {}
  string toStr();
  string evaluate();
};
