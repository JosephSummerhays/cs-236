#include "tuple.h"

using namespace std;

tuple::tuple(predicate tupleValues) {
  for (int i = 0 i < Schema.size(); i++) {
    attributeValues.push_back(tupleValues.getParam(i)->toStr());
  }
}

string tuple::toStr() {
  string toReturn = "";
  for (int i = 0; i < attributeValues.size(); i++) {
    toReturn += " " +attributeValues.at(i);
  }
  return toReturn;
}
