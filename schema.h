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
  void set(vector<string> Schema);
  string at(int i) { return attributeNames.at(i); }
  string toStr();
  schema project(vector<int> col);
};
