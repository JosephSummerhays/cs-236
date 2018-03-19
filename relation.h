#pragma once
#include <string>
#include <set>
#include <schema.h>
#include <tuple.h>

using namespace std;

class relation {
private:
  string name;
  schema* head;
  set<tuple> tuples;
public:
  relation (predicate schemaToAdd);
  void addTuple(predicate tupleToAdd);
};
