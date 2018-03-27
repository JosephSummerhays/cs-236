#include "database.h"

database::database(dataLog &data) {
  for (int i = 0; i < data.getNumSchema(); i++) {
    relation temp(data.schemaAt(i));
    for (int j = 0; j < data.getNumFacts(); j++) {
      if (data.schemaAt(i).getId() == data.factAt(j).getId()) {
        temp.addTuple(data.factAt(j));
      }
    }
    relations.push_back(temp);
  }
  for (int i = 0; i < data.getNumQueries(); i++) {
    //TO DO add Queries
    query temp(data.queryAt(i));
    queries.push_back(temp);
  }
}

string database::toStr() {
  string toReturn = "";
  for (unsigned int i = 0; i < relations.size(); i++) {
    toReturn += relations.at(i).toStr() + "\n\n";
  }
  for (unsigned int i = 0; i < queries.size(); i++) {
    toReturn += queries.at(i).toStr() + "\n\n";
  }
  return toReturn;
}

int count(char c, string toCount) {
  int count = 0;
  for (unsigned int i = 0; i < toCount.size(); i++) {
    if (toCount.at(i) == c) {
      count++;
    }
  }
  return count;
}

string database::evaluate(int i) {
  string query = queries.at(i).toStr();
  string answers = "";
  vector<int> projections;
  vector<string> selections;
  for (unsigned int j = 0; j < queries.size(); j++) {
    if (que)//HERE!!!!!!!!!!!!!!!!!!!!!!
  }
  /*for (unsigned int j = 0; j < relations.size(); j++){
    if (queries.at(i).Name() == relations.at(j).Name()) {
      for (int k = 0; k < relations.at(j).size(); k++) {
        answers += queries.at(i).eval(relations.at(j).at(k));
      }
      if (count('\n', answers) != 0) {
        query += "Yes(" + to_string(count('\n', answers)) + ")\n";
      }
      else {
        query += "No\n";
      }
      break;
    }
  }*/
  return query + answers;
}

string database::evaluate() {
  string toReturn = "";
  for (unsigned int i = 0; i < queries.size(); i++) {
    toReturn += evaluate(i);
  }
  cout << "******** testing select function **********" << endl;
  cout << relations.at(0).toStr() << endl;
  vector<int> projectionCol = {1,2};
  cout << relations.at(0).project(projectionCol).toStr() << endl;
  return toReturn;
}
