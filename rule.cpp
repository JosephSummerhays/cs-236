#include "rule.h"

rule::rule(predicate* headpred) {
  this->headpred = headpred;
}
void rule::push(predicate* toPush) {
  this->predList.push_back(toPush);
}
std::string rule::toStr() {
  std::string toReturn = headpred->toStr() + " :- ";
  for (unsigned int i = 0; i < predList.size(); i++) {
    toReturn += predList.at(i)->toStr() + ",";
  }
  toReturn.pop_back();
  return toReturn;
}
vector<predicate*>& rule::getPredList() {
  return predList;
}
