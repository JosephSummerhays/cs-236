#include "expressionParam.h"

expressionParam::expressionParam () {
  leftParam = NULL;
  rightParam = NULL;
}
expressionParam::~expressionParam() {
  //delete leftParam;
  //delete rightParam;
}
void expressionParam::setLeft (Param* toPoint) {
  leftParam = toPoint;
}
void expressionParam::setRight (Param* toPoint) {
  rightParam = toPoint;
}
void expressionParam::setOperator (Token oprator) {
  this->oprator = oprator;
}
std::string expressionParam::toStr() {
  return "(" + leftParam->toStr() + oprator.getVal() + rightParam->toStr() + ")";
}
