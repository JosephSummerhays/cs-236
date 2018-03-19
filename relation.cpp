#pragma once
#include "relation.h"

relation::relation(predicate schemaToAdd) {
  name = schemaToAdd.id();
  head = new schema(schemaToAdd);
}
void relation::addTuple(predicate tupleToAdd) {
  tuples.push_back(tupleToAdd);
}
