#include "tokenParam.h"

tokenParam::tokenParam(Token parameter) {
  this->parameter = parameter;
}
Token tokenParam::getToken() {
  return parameter;
}
std::string tokenParam::toStr() {
  return parameter.getVal();
}
void tokenParam::setParam(Token parameter) {
  this->parameter = parameter;
}
