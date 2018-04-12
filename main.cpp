#include <iostream>
#include "charList.h"
#include "Scanner.h"
#include "dataLog.h"
#include "database.h"
#include "expressionParam.h"
#include "tokenParam.h"
#include "token.h"


using namespace std;

int main (int argNum, char* args[]) {
  funcMeasure x("main");
  x.flag();
  dataLog dataLoggicus (args[1]);
  try {
    dataLoggicus.build();
    //cout << "Success!\n" << dataLoggicus.toStr();
    database databasicus(dataLoggicus);
    cout << databasicus.evaluate() << endl;
  } catch (string err) {
    cout << "Failure!" << endl;
    cout << "   " << err << endl;
  }
  x.flag();
  x.print();
  return 0;
}
