#include "query.h"

query::query(predicate q) {
  name = q.getId();
  for (int i = 0; i < q.size(); i++) {
    params.push_back(q.getParam(i)->toStr());
  }
  setUnique();
}

bool query::alreadyUnique(string tofind) {
  for (unsigned int i = 0; i < unique.size(); i++) {
    if (unique.at(i) == tofind) {
      return true;
    }
  }
  return false;
}

void query::setUnique() {
  for (unsigned int i = 0; i < params.size(); i++) {
    if (!alreadyUnique(params.at(i))&& params.at(i).at(0) != '\'') {
      unique.push_back(params.at(i));
      toProject.push_back(i);
    }
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

bool query::matches(map<string,string> &paramsToConst,Tuple fact) {
  for (unsigned int i = 0; i < params.size(); i++) {
    if (params.at(i).at(0) != '\'') {
      if (paramsToConst.find(params.at(i))==paramsToConst.end()) { //if we don't find it
        paramsToConst[params.at(i)] = fact.at(i);
        continue;
      }
      if (paramsToConst.at(params.at(i)) != fact.at(i)) {
        return false;
      }
    }
    else {
      if (params.at(i) != fact.at(i)) {
        return false;
      }
    }
  }
  return true;
}

bool query::eval(Tuple fact) {
  if (params.size() != fact.size()) {
    return false;
  }
  map<string,string> paramsToConst;
  if(!matches(paramsToConst, fact)) {
    return false;
  }
  return true;
  // for (map<string, string>::iterator it = paramsToConst.begin();
  //     it != paramsToConst.end(); it++) {
  //   toReturn += it->first + "=" + it->second + ", ";
  // }
  /*
  string found = "";
  for (unsigned int i = 0; i < unique.size(); i++) {
    if (unique.at(i).at(0) != '\'') {
      toReturn += unique.at(i) + "=" + paramsToConst[unique.at(i)] + ", ";
    }
  }
  toReturn.pop_back();
  toReturn.pop_back();
  return toReturn + "\n";*/
}
