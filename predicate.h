#pragma once
#include "param.h"
#include <vector>

class predicate {
private:
  std::vector<Param*> parameters;
  Token id;
public:
  predicate();
  predicate(Token id);
  ~predicate();
  void push(Param* pred);
  Param* getParam(int i);
  std::string toStr();
  std::string getId() { return id.getVal(); }
  int size() { return parameters.size(); }
};
