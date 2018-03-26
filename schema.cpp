#include "schema.h"

using namespace std;

void schema::set(predicate Schema) {
  for (int i = 0; i < Schema.size(); i++) {
    attributeNames.push_back(Schema.getParam(i)->toStr());
  }
}

string schema::toStr() {
  string toReturn = "";
  for (unsigned int i = 0; i < attributeNames.size(); i++) {
    toReturn += " " +attributeNames.at(i);
  }
  return toReturn;
}
schema schema::project(vector<int> col) {
  schema toReturn;
  for (int i = 0; i < col.size(); i++) {
    toReturn.push_back(attributeNames.at(col.at(i)));
  }
  return toReturn;
}
