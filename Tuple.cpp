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

Tuple Tuple::project(vector<int> col) {
  Tuple toReturn;
  for (int i = 0; i < col.size(); i++) {
    toReturn.push_back(at(col.at(i)));
  }
  return toReturn;
}
