#pragma once
#include "Rule.h"
#include <set>

using namespace std;

class graph {
private:
  bool** matrix;
  int size;
  vector<int> postOrder;
  vector<bool> visited;
  vector<set<int>> SCCs;
  void resetVisited();
  void DFSCausality(int col);
  void DFSFindSCC(int row);
public:
  graph(vector<Rule>& rules);
  void findSCC();
  string ToString();
  int numSCC() { return SCCs.size(); }
  set<int> getSCCAt(int i) { return SCCs.at(i); }
  bool recursiveAt(int i) { return matrix[i][i]; }
  ~graph();
};
