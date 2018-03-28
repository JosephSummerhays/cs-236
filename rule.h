#pragma once
#include "predicate.h"

class rule {
private:
  predicate* headpred;
  std::vector<predicate*> predList;
public:
  rule() {}
  rule(predicate* headpred);
  ~rule() {}
  void push(predicate* toPush);
  vector<predicate*>& getPredList();
  std::string toStr();
  predicate getHead() {return (*headpred);}
};
