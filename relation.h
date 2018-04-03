#pragma once
#include <string>
#include <set>
#include "schema.h"
#include "Tuple.h"
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

class relation {
private:
  string name;
  schema head;
  set<Tuple> tuples;
public:
  void addTuple (Tuple tupleToAdd);
  relation () {}
  relation (predicate schemaToAdd);
  relation (schema head) { this->head = head; }
  relation (vector<string> head) { this->head.set(head); }
  schema getHead() const { return head; }
  void addTuple(predicate tupleToAdd);
  string toStr();
  string Name() { return name; }
  int size() const { return tuples.size(); }
  Tuple at(int i) const;
  // relation select(int col1, int col2);
  relation select(string val, int col);
  relation project(vector<int> col);
  void join(const relation& toJoin);
  relation setDifference(relation toSubtract);
  void addSet(relation toAdd);
  void setHead(schema newHead) { head = newHead; }
};
