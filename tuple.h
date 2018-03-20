#pragma once
#include <vector>
#include <string>

using namespace std;

class tuple : public vector<string> {
private:
public:
  tuple(predicate tupleValues);
  string toStr();
};
