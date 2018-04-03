#pragma once
#include <ctime>
#include <iostream>

using namespace std;

class funcMeasure {
private:
  string funcName;
  vector<long int> flags;
public:
  funcMeasure() {
    funcName = "the function";
  }
  funcMeasure(string funcName) {
    this->funcName = funcName;
  }
  void print () {
    cout << "******" << funcName << " took " << *flags.begin() - *(flags.end()-1)
      << " seconds to perform." << endl;
  }
  void flag() {
    flags.push_back(time(NULL));
  }
  void printFull() {
    cout << "****************" << funcName << "*****************" << endl;
    for (unsigned int i = 1; i < flags.size(); i++) {
      cout << "   flag " << i << ": " << flags.at(i) - flags.at(i-1) << endl;
    }
  }
};
