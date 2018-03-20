#include "database.h"

database::database(dataLog data) {
  for (int i = 0; i < data.getNumSchema(); i++) {
    relation temp(data.schemaAt(i));
    for (int j = 0; j < data.getNumFacts(); j++) {
      if (data.schemaAt(i).id() == data.factAt(j).id()) {
        temp.addTuple(data.factAt(j));
      }
    }
    relations.push_back(temp);
  }
}

string database::toStr() {
  string toReturn = "";
  for (int i = 0; i < relations.size(); i++) {
    toReturn += relations.at(i);
  }
  return toReturn;
}
