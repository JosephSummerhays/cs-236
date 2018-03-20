#pragma once
#include <string>
#include <set>
#include "schema.h"
#include "Tuple.h"

using namespace std;

class relation {
private:
  string name;
  schema* head;
  set<Tuple> tuples;
public:
  relation (predicate schemaToAdd);
  void addTuple(predicate tupleToAdd);
  string toString();
};
