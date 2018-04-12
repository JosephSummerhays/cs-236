#include "graph.h"

graph::graph(vector<Rule>& rules) {
  size = rules.size();
  matrix = new bool*[size];
  for (int i = 0; i < size; i++) {
    matrix[i] = new bool[size];
  }
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      matrix[j][i] = rules.at(i).causes(rules.at(j));
    }
  }
  visited.resize(size, false);
}

void graph::findSCC() {
  for (unsigned int i = 0; i < visited.size(); i++) {
    if (!visited.at(i)) {
      visited.at(i) = true;
      DFSCausality(i);
    }
  }
  // GET SCCs
  resetVisited();
  for (int i = postOrder.size() - 1; i >= 0; i--){
    if (!visited.at(postOrder.at(i))) {
      visited.at(postOrder.at(i)) = true;
      SCCs.resize(SCCs.size()+1);
      DFSFindSCC(postOrder.at(i));
    }
  }
  // for(unsigned int i = 0; i < SCCs.size(); i++) {
  //   for(set<int>::iterator it = SCCs.at(i).begin(); it != SCCs.at(i).end(); it++) {
  //     cout << ' ' << (*it);
  //   }
  //   cout << endl;
  // }
}

void graph::DFSCausality(int col) {
  for (int i = 0; i < size; i++) {
    if (matrix[i][col] && !visited.at(i)) {
      visited.at(i) = true;
      DFSCausality(i);
    }
  }
  postOrder.push_back(col);
}

void graph::DFSFindSCC(int row) {
  for (int i = 0; i < size; i++) {
    if (matrix[row][i] && !visited.at(i)) {
      visited.at(i) = true;
      DFSFindSCC(i);
    }
  }
  SCCs.back().insert(row);
}

void graph::resetVisited() {
  for(auto iter : visited) { iter = false;  }
}

string graph::ToString() {
  string toReturn = "Dependency Graph";


  for (int i = 0; i < size; i++) {
    toReturn += "\nR"+to_string(i)+":";
    for (int j = 0; j < size; j++) {
      if (matrix[i][j]){
        toReturn += "R"+to_string(j)+",";
      }
    }
    if(toReturn.back() == ','){
      toReturn.pop_back();
    }
  }
  return toReturn;
}

graph::~graph() {
  for (int i = 0; i < size; i++) {
    delete[] matrix[i];
  }
  delete[] matrix;
}
