#include "charList.h"

using namespace std;

charList::charList (string fileName) {
  file.open (fileName);
  lineNum = 1;
}
charList::charList () {
  lineNum = 1;
}
void charList::open (string fileName) {
  file.open(fileName);
}
char charList::get() {
  char toReturn = file.get();
  if (toReturn == '\n') {
    lineNum++;
  }
  return toReturn;
}
int charList::getlineNum() {
  return lineNum;
}
bool charList::isNext(char toCheck) {
  return toCheck == file.peek();
}
bool charList::eof() {
  return file.peek() == char_traits<char>::eof();
}
char charList::getPeek() {
  return file.peek();
}
