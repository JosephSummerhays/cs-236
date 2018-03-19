#include "dataLog.h"
#include <iostream>
using namespace std;

dataLog::dataLog(string fileName) {
  input.open(fileName);
  input.scan();
}
void dataLog::build() {
    grammerStart();
    if (!input.empty()) {
      throw input.top()->toStr();
    }
}
void dataLog::grammerStart() {
  push(Token::SCHEMES);
  push(Token::COLON);
  Schemes.push_back(schemes());
  schemeList();
  push(Token::FACTS);
  push(Token::COLON);
  factList();
  push(Token::RULES);
  push(Token::COLON);
  rulesList();
  push(Token::QUERIES);
  push(Token::COLON);
  Queries.push_back(query());
  queryList();
  push(Token::ENDFILE);
}
predicate* dataLog::schemes() {
  if (input.top()->getType()==Token::ID){
    return headPredicate();
  }
  else {
    throw input.top()->toStr();
  }
}
void dataLog::schemeList() {
  if (input.top()->getType()==Token::ID) {
    Schemes.push_back(schemes());
    schemeList();
  }
}
predicate* dataLog::headPredicate() {
  predicate* tmp = new predicate(push(Token::ID));
  predsToDelete.push_back(tmp);
  push(Token::LEFT_PAREN);
  paramsToDelete.push_back(new tokenParam(push(Token::ID)));
  tmp->push(paramsToDelete.at(paramsToDelete.size()-1));
  idList(tmp);
  push(Token::RIGHT_PAREN);
  return tmp;
}
void dataLog::idList(predicate* &tmp) {
  if (input.top()->getType()==Token::COMMA) {
    push(Token::COMMA);
    paramsToDelete.push_back(new tokenParam(push(Token::ID)));
    tmp->push(paramsToDelete.at(paramsToDelete.size()-1));
    idList(tmp);
  }
}
void dataLog::factList() {
  if (input.top()->getType() == Token::ID) {
    Facts.push_back(fact());
    factList();
  }
}
predicate* dataLog::fact() {
  predicate* tmp = new predicate(push(Token::ID));
  predsToDelete.push_back(tmp);
  push(Token::LEFT_PAREN);
  domain.insert(input.top()->getVal());
  paramsToDelete.push_back(new tokenParam(push(Token::STRING)));
  tmp->push(paramsToDelete.at(paramsToDelete.size()-1));
  stringList(tmp);
  push(Token::RIGHT_PAREN);
  push(Token::PERIOD);
  return tmp;
}
void dataLog::stringList(predicate* &tmp) {
  if (input.top()->getType() == Token::COMMA) {
    push(Token::COMMA);
    domain.insert(input.top()->getVal());
    paramsToDelete.push_back(new tokenParam(push(Token::STRING)));
    tmp->push(paramsToDelete.at(paramsToDelete.size()-1));
    stringList(tmp);
  }
}
void dataLog::rulesList() {
  if(input.top()->getType()==Token::ID) {
    Rules.push_back(Rule());
    rulesList();
  }
}
rule* dataLog::Rule() {
  rule* tmp = new rule(headPredicate());
  push(Token::COLON_DASH);
  tmp->push(Predicate());
  predicateList(tmp->getPredList());
  push(Token::PERIOD);
  return tmp;
}
predicate* dataLog::Predicate() {
  predicate* tmp = new predicate(push(Token::ID));
  predsToDelete.push_back(tmp);
  push(Token::LEFT_PAREN);
  tmp->push(parameter());
  parameterList(tmp);
  push(Token::RIGHT_PAREN);
  return tmp;
}
void dataLog::predicateList(vector<predicate*> &tmp) {
  if (input.top()->getType() == Token::COMMA) {
    push(Token::COMMA);
    tmp.push_back(Predicate());
    predicateList(tmp);
  }
}
Param* dataLog::parameter() {
  Param* temp = NULL;
  if (input.top()->getType() == Token::STRING) {
    temp = new tokenParam(push(Token::STRING));
    paramsToDelete.push_back(temp);
    return temp;
  }
  if (input.top()->getType() ==Token::ID) {
    temp = new tokenParam (push(Token::ID));
    paramsToDelete.push_back(temp);
    return temp;
  }
  if (input.top()->getType() == Token::LEFT_PAREN) {
    temp = expression();
    return temp;
  }
  throw input.top()->toStr();
}
void dataLog::parameterList(predicate* &tmp) {
  if (input.top()->getType() == Token::COMMA) {
    push(Token::COMMA);
    tmp->push(parameter());
    parameterList(tmp);
  }
}
expressionParam* dataLog::expression() {
  expressionParam* temp = new expressionParam;
  paramsToDelete.push_back(temp);
  push(Token::LEFT_PAREN);
  temp->setLeft(parameter());
  temp->setOperator(oprator());
  temp->setRight(parameter());
  push(Token::RIGHT_PAREN);
  return temp;
}
Token dataLog::oprator() {
  if (input.top()->getType() == Token::ADD) {
    return push(Token::ADD);
  }
  else {
    return push(Token::MULTIPLY);
  }
}
predicate* dataLog::query() {
  predicate* tmp = Predicate();
  push(Token::Q_MARK);
  return tmp;
}
void dataLog::queryList() {
  if (input.top()->getType() == Token::ID) {
    Queries.push_back(query());
    queryList();
  }
}
Token dataLog::push(Token::tokentype expected) {
  if (input.top()->getType() == expected) {
    Token temp(expected, input.top()->getVal(), 0);
    input.pop();
    return temp;
  }
  else {
    throw input.top()->toStr();
  }
}

string dataLog::toStr() {
  string toReturn = "Schemes(";
  toReturn += to_string(Schemes.size()) + "):\n";
  for (unsigned int i = 0; i<Schemes.size(); i++) {
    toReturn += "   " + Schemes.at(i)->toStr() + "\n";
  }
  toReturn += "Facts(" + to_string(Facts.size()) + "):\n";
  for (unsigned int i = 0; i<Facts.size(); i++) {
    toReturn += "   " + Facts.at(i)->toStr() + ".\n";
  }
  toReturn += "Rules(" + to_string(Rules.size()) + "):\n";
  for (unsigned int i = 0; i<Rules.size(); i++) {
    toReturn+= "   " + Rules.at(i)->toStr() + ".\n";
  }
  toReturn += "Queries(" + to_string(Queries.size()) +"):\n";
  for (unsigned int i =0; i<Queries.size(); i++) {
    toReturn += "  " + Queries.at(i)->toStr() + "?\n";
  }
  toReturn += "Domain(" + to_string(domain.size()) + "):\n";
  for (set<string>::iterator it=domain.begin(); it != domain.end(); ++it) {
    toReturn += "   " + *it + "\n";
  }
  return toReturn;
}

dataLog::~dataLog() {
  /*for (int i = Schemes.size(); i>=0; --i) {
    delete Schemes.at(i);
  }for (int i = Facts.size(); i>=0; --i) {
    delete Facts.at(i);
  }for (int i = Queries.size(); i>=0; --i) {
    delete Queries.at(i);
  }*/
  for (int i = Rules.size()-1; i>=0; --i) {
    delete Rules.at(i);
  }
  for (int i = paramsToDelete.size()-1; i >=0; --i) {
    delete paramsToDelete.at(i);
  }
  for (int i = predsToDelete.size()-1; i>=0; --i) {
    delete predsToDelete.at(i);
  }
}
