#pragma once
#include <string>
#include <set>
#include "schema.h"
#include "Tuple.h"
#include <iostream>

using namespace std;

class relation {
private:
  vector<string> unique;
  string name;
  schema head;
  set<Tuple> tuples;
  relation (schema head) { this->head = head; }
  void addTuple (Tuple tupleToAdd);
public:
  relation (predicate schemaToAdd);
  relation (schema head) { this->head = head; }
  relation (vector<string> head) { this->head.set(head); }
  schema getHead() { return head; }
  void addTuple(predicate tupleToAdd);
  string toStr();
  string Name() { return name; }
  int size() { return tuples.size(); }
  Tuple at(int i);
  relation select(int col1, int col2);
  relation select(string val, int col);
  relation project(vector<int> col);
};
