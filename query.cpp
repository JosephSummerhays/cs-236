#include "query.h"

query::query(predicate q) {
  name = q.getId();
  for (int i = 0; i < q.size(); i++) {
    params.push_back(q.getParam(i)->toStr());
  }
}

string query::toStr() {
  string toReturn = name+ "(";
  for (unsigned int i = 0; i < params.size(); i++) {
    toReturn += params.at(i) + ",";
  }
  toReturn.pop_back();
  return toReturn+")? ";
}

string query::eval(Tuple fact) {
  string toReturn = "";
  if (params.size() != fact.size()) {
    return toReturn;
  }
  map<string, string> paramsToConst;
  for (unsigned int i = 0; i < params.size(); i++) {
    if (params.at(i).at(0) != '\'') {
      if (paramsToConst.find(params.at(i))==paramsToConst.end()) { /*if we don't find it*/
        paramsToConst[params.at(i)] = fact.at(i);
        continue;
      }
      if (paramsToConst.at(params.at(i)) != fact.at(i)) {
        return toReturn;
      }
    }
    else {
      if (params.at(i) != fact.at(i)) {
        return toReturn;
      }
    }
  }
  toReturn +=  "  ";
  // for (map<string, string>::iterator it = paramsToConst.begin();
  //     it != paramsToConst.end(); it++) {
  //   toReturn += it->first + "=" + it->second + ", ";
  // }
  for (unsigned int i = 0; i < params.size(); i++) {
    if (params.at(i).at(0) != '\'') {
      toReturn += params.at(i) + "=" + paramsToConst[params.at(i)] + ", ";
    }
  }
  toReturn.pop_back();
  toReturn.pop_back();
  return toReturn + "\n";
}
