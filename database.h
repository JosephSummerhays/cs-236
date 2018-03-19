#pragma once
#include <dataLog.h>
#include <vector>
#include <relation.h>

using namespace std;

class database {
private:
  vector<relation> relations;
public:
  database(dataLog data);
};
