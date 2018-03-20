#include "Tuple.h"

using namespace std;

Tuple::Tuple(predicate tupleValues) {
  for (unsigned int i = 0 i < Schema.size(); i++) {
    push_back(tupleValues.getParam(i)->toStr());
  }
}

string Tuple::toStr() {
  string toReturn = "";
  for (unsigned int i = 0; i < size(); i++) {
    toReturn += " " + at(i);
  }
  return toReturn;
}
