#pragma once
#include "predicate.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Tuple : public vector<string> {
private:
  Tuple(){ }
public:
  Tuple(predicate tupleValues);
  Tuple project(vector<int> col);
  string toStr() const;
};
