#pragma once
#include "relation.h"

relation::relation(predicate schemaToAdd) {
  name = schemaToAdd.id();
  head = new schema(schemaToAdd);
}
void relation::addTuple(predicate tupleToAdd) {
  tuples.push_back(tupleToAdd);
}
string relation::toStr() {
  string toReturn = head->toStr() + "\n";
  for (int i = 0; i < tuples.size(); i++) {
    toReturn += tuples.at(i)->toStr() + "\n";
  }
  return toReturn;
}
