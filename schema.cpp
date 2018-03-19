#include "schema.h"

using namespace std;

schema::schema(predicate Schema) {
  for (int i = 0; i < Schema.size(); i++) {
    attributeNames.push_back(Schema.getParam(i)->toStr());
  }
}

string schema::toStr() {
  string toReturn = "";
  for (int i = 0; i < attributeNames.size(); i++) {
    toReturn += " " +attributeNames.at(i);
  }
  return toReturn;
}
