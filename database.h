#pragma once
#include "dataLog.h"
#include "relation.h"
#include "query.h"
#include <vector>
#include <iostream>

using namespace std;

class database {
private:
  vector<relation> relations;
  vector<query> queries;
  string evaluate(int i);
public:
  database(dataLog &data);
  database() {}
  string toStr();
  string evaluate();
};
