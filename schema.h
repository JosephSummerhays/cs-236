#pragma once
#include "predicate.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class schema {
private:
  vector<string> attributeNames;
public:
  schema() {}
  void set(predicate Schema);
  string toStr();
  schema project(vector<int> col);
};
