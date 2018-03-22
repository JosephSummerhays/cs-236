#pragma once
#include "predicate.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Tuple : public vector<string> {
private:
public:
  Tuple(predicate tupleValues);
  string toStr() const;
};
