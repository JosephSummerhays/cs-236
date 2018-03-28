#include "relation.h"

relation::relation(predicate schemaToAdd) {
  name = schemaToAdd.getId();
  head.set(schemaToAdd);
}
void relation::addTuple(predicate tupleToAdd) {
  tuples.insert(tupleToAdd);
}
void relation::addTuple(Tuple tupleToAdd) {
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

relation relation::select(int col1, int col2) {
  relation toReturn(head);
  for (set<Tuple>::iterator it = tuples.begin(); it != tuples.end(); it++) {
    if (it->at(col1) == it->at(col2)) {
      toReturn.addTuple((*it));
    }
  }
  return toReturn;
}
relation relation::select(string val, int col) {
  relation toReturn(head);
  for (set<Tuple>:: iterator it = tuples.begin(); it != tuples.end(); it++) {
    if (it->at(col) == val) {
      toReturn.addTuple(*it);
    }
  }
  return toReturn;
}
relation relation::project(vector<int> col) {
  relation toReturn(head.project(col));
  for (set<Tuple>:: iterator it = tuples.begin(); it != tuples.end(); it++) {
    Tuple temp = (*it);
    toReturn.addTuple(temp.project(col));
  }
  return toReturn;
}

bool relation::alreadyUnique(string tofind) {
  for (unsigned int i = 0; i < unique.size(); i++) {
    if (unique.at(i) == tofind) {
      return true;
    }
  }
  return false;
}

void relation::setUnique() {
  for (unsigned int i = 0; i < head.size(); i++) {
    if (!alreadyUnique(head.at(i))) {
      unique.push_back(head.at(i));//HERE!!!!!!!!!!!!!!!!!!!!!
    }
  }
}
