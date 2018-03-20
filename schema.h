#pragma once
#include "predicate.h"
#include <vector>
#include <string>

using namespace std;

class schema {
private:
  vector<string> attributeNames;
public:
  schema (predicate Schema);
  string toStr();
};
