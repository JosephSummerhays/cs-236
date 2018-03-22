#pragma once
#include <string>
#include <set>
#include "schema.h"
#include "Tuple.h"
#include <iostream>

using namespace std;

class relation {
private:
  string name;
  schema head;
  set<Tuple> tuples;
public:
  relation (predicate schemaToAdd);
  void addTuple(predicate tupleToAdd);
  string toStr();
  string Name() { return name; }
  int size() { return tuples.size(); }
  Tuple at(int i);
};
