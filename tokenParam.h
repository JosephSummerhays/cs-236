#pragma once
#include "param.h"

class tokenParam : public Param {
private:
  Token parameter;
public:
  tokenParam() {}
  tokenParam(Token parameter);
  void setParam(Token parameter);
  std::string toStr();
  Token getToken();
};
