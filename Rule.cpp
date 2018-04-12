#include "Rule.h"

Rule::Rule(rule toConstruct) {
  conclusionName = toConstruct.getHead().getId();
  conclusion.set(toConstruct.getHead());
  for (unsigned int i = 0; i < toConstruct.getPredList().size(); ++i) {
    premises.push_back(query(*toConstruct.getPredList().at(i)));
  }
}
string Rule::toStr() {
  string prems = "";
  for (unsigned int i = 0; i < premises.size(); i++) {
    prems += premises.at(i).toStr();
    prems.pop_back();
    prems.pop_back();
    prems += ",";
  }
  prems.pop_back();
  return conclusionName + "(" + conclusion.toStr() + ") :- " + prems;
}

bool Rule::causes(const Rule& toCompare) {
  for (int i = 0; i < toCompare.size(); i++) {
    if (conclusionName == toCompare.premiseAt(i).Name()) {
      return true;
    }
  }
  return false;
}
