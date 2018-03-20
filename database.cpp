#include "database.h"

database::database(dataLog &data) {
  for (int i = 0; i < data.getNumSchema(); i++) {
    relation temp(data.schemaAt(i));
    for (int j = 0; j < data.getNumFacts(); j++) {
      if (data.schemaAt(i).getId() == data.factAt(j).getId()) {
        temp.addTuple(data.factAt(j));
      }
    }
    relations.push_back(temp);
  }
}

string database::toStr() {
  string toReturn = "";
  for (unsigned int i = 0; i < relations.size(); i++) {
    toReturn += relations.at(i).toString() + "\n\n";
  }
  return toReturn;
}
