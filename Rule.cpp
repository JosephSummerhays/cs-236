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
    prems += premises.at(i).toStr() + "\n";
  }
  return conclusionName + "(" + conclusion.toStr() + "):-\n" + prems;
}
