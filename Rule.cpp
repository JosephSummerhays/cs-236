#include "Rule.h"

Rule::Rule(rule toCopy) {
  conclusion.set(toCopy.getHead());
}
