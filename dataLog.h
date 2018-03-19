#pragma once
#include <set>
#include "Scanner.h"
#include "rule.h"
#include "tokenParam.h"
#include "expressionParam.h"

using namespace std;

class dataLog {
private:
  Scanner input;
  set<string> domain;
  vector<predicate*> Schemes;
  vector<predicate*> Facts;
  vector<predicate*> Queries;
  vector<rule*> Rules;
  vector<Param*> paramsToDelete;
  vector<predicate*> predsToDelete;

  void grammerStart();
  predicate* schemes();
  void schemeList();
  predicate* headPredicate();
  void idList(predicate* &tmp);
  void factList();
  predicate* fact();
  void stringList(predicate* &tmp);
  void rulesList();
  rule* Rule();
  predicate* Predicate();
  void predicateList(vector<predicate*>& tmp);
  Param* parameter();
  void parameterList(predicate* &tmp);
  expressionParam* expression();
  Token oprator();
  predicate* query();
  void queryList();
  Token push(Token::tokentype expected);
public:
  dataLog(string fileName);
  ~dataLog();
  void build();
  string toStr();
  int getNumSchema() { return Schemes.size(); }
  int getNumFacts() { return Facts.size(); }
  predicate schemaAt(int i) {return *(Schemes.at(i));}
  predicate factAt(int i) {return *(Facts.at(i));}
};
