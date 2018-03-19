#include "Scanner.h"
#include <iostream>
#include <cctype>
using namespace std;

Scanner::Scanner (string fileName) {
  daChars.open(fileName);
}
Scanner::~Scanner() {
  for (int i = tokenList.size() - 1; i >= 0; i--) {
    delete tokenList.at(i);
  }
}
void Scanner::open (string fileName) {
  daChars.open(fileName);
}
void Scanner::scan() {
  while (!daChars.eof()) {
    char cur = daChars.get();
    switch (cur) {
      case ',': {
        tokenList.push_back(new Token(Token::COMMA, ",", daChars.getlineNum()));
      } break;
      case '.': {
        tokenList.push_back(new Token(Token::PERIOD, ".", daChars.getlineNum()));
      } break;
      case '?': {
        tokenList.push_back(new Token(Token::Q_MARK, "?", daChars.getlineNum()));
      } break;
      case '(': {
        tokenList.push_back(new Token(Token::LEFT_PAREN, "(", daChars.getlineNum()));
      } break;
      case ')': {
        tokenList.push_back(new Token(Token::RIGHT_PAREN, ")", daChars.getlineNum()));
      } break;
      case ':': {
        if (daChars.isNext('-')) {
          daChars.get();
          tokenList.push_back(new Token(Token::COLON_DASH, ":-", daChars.getlineNum()));
        }
        else {
          tokenList.push_back(new Token(Token::COLON, ":", daChars.getlineNum()));
        }
      } break;
      case '*': {
        tokenList.push_back(new Token(Token::MULTIPLY, "*", daChars.getlineNum()));
      } break;
      case '+': {
        tokenList.push_back(new Token(Token::ADD, "+", daChars.getlineNum()));
      } break;
      case '\'': {
        string toConstructor  = "'";
        int lineNum = daChars.getlineNum();
        if (getString(toConstructor)){
          tokenList.push_back(new Token(Token::STRING, toConstructor, lineNum));
        }
        else {
          tokenList.push_back(new Token(Token::UNDEFINED, toConstructor, lineNum));
        }
      } break;
      case '#': {
        comment(cur);
      } break;
      default : {
        defaultFunc(cur);
      } break;
    }
  }
  tokenList.push_back(new Token(Token::ENDFILE, "", daChars.getlineNum()));
}
void Scanner::comment(char cur) {
  int lineNum = daChars.getlineNum();
  if (daChars.isNext('|')) {
    string toConstr;
    toConstr = toConstr + cur + daChars.get();
    if (getMultiComment(toConstr)) {
      //tokenList.push_back(new Token(Token::COMMENT, toConstr, lineNum)); // we no longer want to store comments
    } else {
      tokenList.push_back(new Token(Token::UNDEFINED, toConstr, lineNum));
    }
  } else {
    string toConstr;
    toConstr = toConstr + cur;
    if (getSingleComment(toConstr)) {
      //tokenList.push_back(new Token(Token::COMMENT, toConstr, lineNum)); // we no longer want to store comments
    } else {
      tokenList.push_back(new Token(Token::UNDEFINED, toConstr, lineNum));
    }
  }
}
void Scanner::defaultFunc(char cur) {
  string toConstr;
  toConstr = toConstr + cur;
  int lineNum = daChars.getlineNum();
  if (isalpha(cur)) {
    getID(toConstr);
    if (toConstr == "Schemes") {
      tokenList.push_back(new Token(Token::SCHEMES, toConstr, lineNum));
    } else if (toConstr == "Facts") {
      tokenList.push_back(new Token(Token::FACTS, toConstr, lineNum));
    } else if (toConstr == "Rules") {
      tokenList.push_back(new Token(Token::RULES, toConstr, lineNum));
    } else if (toConstr == "Queries") {
      tokenList.push_back(new Token(Token::QUERIES, toConstr, lineNum));
    } else {
      tokenList.push_back(new Token(Token::ID, toConstr, lineNum));
    }
  } else if (!isspace(cur)) {
    tokenList.push_back(new Token(Token::UNDEFINED, toConstr, lineNum));
  }
}
void Scanner::print() {
  for (unsigned int i = 0; i < tokenList.size(); i++) {
    cout << tokenList.at(i)->toStr() << endl;
  }
  cout << "Total Tokens = " << tokenList.size() << endl;
}
bool Scanner::getString(string& toReturn) {
  while (true) {
    if (daChars.eof()) {
      return false;
    }
    char toAppend = daChars.get();

    if (toAppend == '\'') {
      if (daChars.isNext('\'')) {
        toReturn = toReturn + toAppend + daChars.get();
      } else {
        toReturn = toReturn + toAppend;
        return true;
      }
    } else {
      toReturn = toReturn + toAppend;
    }
  }
}
bool Scanner::getSingleComment(string& toReturn) {
  while (!daChars.isNext('\n')) {
    if (daChars.eof()) {
      return false;
    }
    toReturn = toReturn + daChars.get();
  }
  return true;
}
bool Scanner::getMultiComment(string& toReturn) {
  while (true) {
    char toAppend = daChars.get();
    if (toAppend == '|' && daChars.isNext('#')) {
      toReturn = toReturn + toAppend + daChars.get();
      return true;
    } else if (daChars.eof()) {
      toReturn = toReturn + toAppend;
      return false;
    }
    toReturn = toReturn + toAppend;
  }
}
void Scanner::getID(string& toReturn) {
  while (isalnum(daChars.getPeek())) {
    toReturn = toReturn + daChars.get();
  }
}
Token* Scanner::top() {
  return tokenList.at(0);
}
void Scanner::pop() {
  delete tokenList.at(0)
  tokenList.erase(tokenList.begin());
}
