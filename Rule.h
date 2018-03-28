#pragma once
#include "rule.h"
#include "schema.h"
#include "query.h"

using namespace std;

class Rule {
public:
  Rule(rule toCopy);
private:
  schema conclusion;
  vector<query> premises;
}
