#include "predicate.h"

predicate::predicate() {}
predicate::predicate(Token id) {
  this->id = id;
}
predicate::~predicate() {
  //for (int i=parameters.size()-1; i>=0; i--) {
  //  delete parameters.at(i);
  //}
}
void predicate::push(Param* pred) {
  parameters.push_back(pred);
}
Param* predicate::getParam(int i) {
  return parameters.at(i);
}
std::string predicate::toStr() {
  std::string toReturn = id.getVal() + "(";
  for (unsigned int i = 0; i < parameters.size(); i++) {
    toReturn += parameters.at(i)->toStr() + ",";
  }
  toReturn.pop_back();
  return toReturn + ")";
}
