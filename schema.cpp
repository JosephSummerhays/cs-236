#include "schema.h"

using namespace std;

void schema::set(predicate Schema) {
  for (int i = 0; i < Schema.size(); i++) {
    attributeNames.push_back(Schema.getParam(i)->toStr());
  }
}

void schema::set(vector<string> Schema) {
  attributeNames = Schema;
}

string schema::toStr() {
  string toReturn = "";
  for (unsigned int i = 0; i < attributeNames.size(); i++) {
    toReturn += attributeNames.at(i)+ ",";
  }
  toReturn.pop_back();
  return toReturn;
}
schema schema::project(vector<int> col) {
  schema toReturn;
  for (unsigned int i = 0; i < col.size(); i++) {
    toReturn.attributeNames.push_back(attributeNames.at(col.at(i)));
  }
  return toReturn;
}
void schema::join(schema toJoin) {
  map<string,int> m;
  for (unsigned int i = 0; i < attributeNames.size(); i++){
    m[attributeNames.at(i)] = i;
  }
  for (int i = 0; i < toJoin.size(); i++) {
    if(m.find(toJoin.at(i)) == m.end()) {
      attributeNames.push_back(toJoin.at(i));
    }
  }
}
