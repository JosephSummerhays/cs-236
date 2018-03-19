#pragma once
#include "param.h"

class expressionParam : public Param {
private:
  Param* leftParam;
  Param* rightParam;
  Token oprator;
public:
  expressionParam();
  ~expressionParam();
  void setLeft(Param* toPoint);
  void setRight(Param* toPoint);
  void setOperator(Token oprator);
  std::string toStr();
};
