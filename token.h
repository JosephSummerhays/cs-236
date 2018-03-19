#pragma once
#include <string>
#include <map>
using namespace std;



class Token {
  friend class dataLog;
public:
  enum tokentype {COMMA, PERIOD, Q_MARK, LEFT_PAREN, RIGHT_PAREN, COLON,
    COLON_DASH, MULTIPLY, ADD, SCHEMES, FACTS, RULES, QUERIES, ID, STRING,
    COMMENT, UNDEFINED, ENDFILE};

  static map<tokentype, string> typeKey;
  Token(tokentype type, string value, int lineNum);
  Token() {}
  string toStr();
  tokentype getType() {return type;}
  string getVal() {return value;}
  int getlineNum() {return lineNum;}
private:
  tokentype type;
  string value;
  int lineNum;
};
