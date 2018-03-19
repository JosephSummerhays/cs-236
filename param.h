#pragma once
#include "token.h"

class Param {
public:
  virtual string toStr() = 0;
  virtual ~Param() = 0;
};






/*#pragma once
#include "token.h"
#include <vector>
#include <string>

class paramList {
private:
  std::vector<Token> parameters;
public:
  void push(Token param);
  Token getToken(int i);
  paramList();
  ~paramList();
}
*/
