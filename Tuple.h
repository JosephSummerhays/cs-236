#pragma once
#include <vector>
#include <string>

using namespace std;

class Tuple : public vector<string> {
private:
public:
  Tuple(predicate tupleValues);
  string toStr();
};
