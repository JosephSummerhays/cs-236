#include "Tuple.h"

using namespace std;

Tuple::Tuple(predicate tupleValues) {
  for (int i = 0; i < tupleValues.size(); i++) {
    push_back(tupleValues.getParam(i)->toStr());
  }
}

string Tuple::toStr() const{
  string toReturn = "";
  for (unsigned int i = 0; i < size(); i++) {
    toReturn += " " + at(i);
  }
  return toReturn;
}
