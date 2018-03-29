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
  string toReturn = "";
  for (set<Tuple>::iterator it = tuples.begin(); it != tuples.end(); it++) {
    toReturn += "   ";
    for (unsigned int i = 0; i < it->size(); i++) {
      toReturn += head.at(i) + "=" + it->at(i) + ", ";
    }
    toReturn.pop_back();
    toReturn.pop_back();
    toReturn += "\n";
  }
  // string toReturn = head.toStr() + "\n";
  // for (set<Tuple>::iterator it = tuples.begin(); it != tuples.end(); it++) {
  //   toReturn += it->toStr() + "\n";
  // }
  return toReturn;
}

Tuple relation::at(int i) {
  set<Tuple>::iterator it = tuples.begin();
  advance(it, i);
  return *it;
}

// relation relation::select(int col1, int col2) {
//   relation toReturn(head);
//   for (set<Tuple>::iterator it = tuples.begin(); it != tuples.end(); it++) {
//     if (it->at(col1) == it->at(col2)) {
//       toReturn.addTuple((*it));
//     }
//   }
//   return toReturn;
// }
// relation relation::select(string val, int col) {
//   relation toReturn(head);
//   for (set<Tuple>:: iterator it = tuples.begin(); it != tuples.end(); it++) {
//     if (it->at(col) == val) {
//       toReturn.addTuple(*it);
//     }
//   }
//   return toReturn;
// }
relation relation::project(vector<int> col) {
  relation toReturn(head.project(col));
  for (set<Tuple>:: iterator it = tuples.begin(); it != tuples.end(); it++) {
    Tuple temp = (*it);
    toReturn.addTuple(temp.project(col));
  }
  return toReturn;
}

bool joinable(Tuple& t1, Tuple t2, schema s1, schema s2) {
  map<string,int> m;
  for (int i = 0; i < s1.size(); i++){
    m[s1.at(i)] = i;
  }
  for (int i = 0; i < s2.size(); i++) {
    if(m.find(s2.at(i)) != m.end()) {
      if (t2.at(i) != t1.at(m[s2.at(i)])) {
        return false;
      }
    }
    else {
      t1.push_back(t2.at(i));
    }
  }
  return true;
}

void relation::join(relation toJoin) {
  set<Tuple> toReplace;

  for (set<Tuple>::iterator it = tuples.begin(); it != tuples.end(); it++) {
    for (int i = 0; i < toJoin.size(); i++){
      Tuple tmp = (*it);
      //cout << tmp.toStr() << " + " << toJoin.at(i).toStr() << " -> ";
      if (joinable(tmp, toJoin.at(i), head, toJoin.getHead())) {
        toReplace.insert(tmp);
        //cout << tmp.toStr();
      }
      //cout << endl;
    }
  }
  // for (set<Tuple>::iterator it = toReplace.begin(); it != toReplace.end(); it++) {
  //   cout << it->toStr() << endl;
  // }
  tuples = toReplace;
  head.join(toJoin.getHead());
}
