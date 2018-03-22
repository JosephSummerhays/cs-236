#include "relation.h"

relation::relation(predicate schemaToAdd) {
  name = schemaToAdd.getId();
  head.set(schemaToAdd);
}
void relation::addTuple(predicate tupleToAdd) {
  tuples.insert(tupleToAdd);
}
string relation::toStr() {
  string toReturn = head.toStr() + "\n";
  for (set<Tuple>::iterator it = tuples.begin(); it != tuples.end(); it++) {
    toReturn += it->toStr() + "\n";
  }
  return toReturn;
}
Tuple relation::at(int i) {
  set<Tuple>::iterator it = tuples.begin();
  advance(it, i);
  return *it;
}
