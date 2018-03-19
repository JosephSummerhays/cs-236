#include "token.h"
using namespace std;

string Token::toStr(){
  return "(" + typeKey[type] + ",\"" + value + "\"," + to_string(lineNum) + ")";
}
Token::Token(tokentype type, string value, int lineNum) {
  this->type = type;
  this->value = value;
  this->lineNum = lineNum;
}

map<Token::tokentype, string> Token::typeKey = {
    {COMMA, "COMMA"},
    {PERIOD, "PERIOD"},
    {Q_MARK, "Q_MARK"},
    {LEFT_PAREN, "LEFT_PAREN"},
    {RIGHT_PAREN, "RIGHT_PAREN"},
    {COLON, "COLON"},
    {COLON_DASH, "COLON_DASH"},
    {MULTIPLY, "MULTIPLY"},
    {ADD, "ADD"},
    {SCHEMES, "SCHEMES"},
    {FACTS, "FACTS"},
    {RULES, "RULES"},
    {QUERIES, "QUERIES"},
    {ID, "ID"},
    {STRING, "STRING"},
    {COMMENT, "COMMENT"},
    {UNDEFINED, "UNDEFINED"},
    {ENDFILE, "EOF"}
  };
