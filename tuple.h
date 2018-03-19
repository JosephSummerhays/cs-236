#pragma once
#include <vector>
#include <string>

using namespace std;

class tuple {
private:
  vector<string> attributeValues;
public:
  tuple(predicate tupleValues);
  string toStr();
};
