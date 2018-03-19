#include <iostream>
#include "charList.h"
#include "Scanner.h"
#include "dataLog.h"
#include "expressionParam.h"
#include "tokenParam.h"
#include "token.h"


using namespace std;

int main (int argNum, char* args[]) {
  dataLog dataLoggicus (args[1]);
  try {
    dataLoggicus.build();
    //cout << "Success!\n" << dataLoggicus.toStr();
  } catch (string err) {
    cout << "Failure!" << endl;
    cout << "   " << err << endl;
  }
  
  return 0;
}
