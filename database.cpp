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

    query temp(data.queryAt(i));
    queries.push_back(temp);
  }

  for (int i = 0; i < data.getNumRules(); i++) {
    rules.push_back(Rule(data.ruleAt(i)));
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
  /*
  // string answers = "";
  // vector<int> projections;
  // vector<string> selections;
  // for (unsigned int j = 0; j < queries.size(); j++) {
  //   if (que)//HERE!!!!!!!!!!!!!!!!!!!!!!
  // }
  for (unsigned int j = 0; j < relations.size(); j++){
    if (queries.at(i).Name() == relations.at(j).Name()) {
      relation toReturn(relations.at(j).getHead());
      for (int k = 0; k < relations.at(j).size(); k++) {
        if (queries.at(i).eval(relations.at(j).at(k))) {
          toReturn.addTuple(relations.at(j).at(k));
        }
      }
      // if (count('\n', answers) != 0) {
      //   query += "Yes(" + to_string(count('\n', answers)) + ")\n";
      // }
      // else {
      //   query += "No\n";
      // }
      return toReturn;
      // break;
    }
  }*/
  string q = queries.at(i).toStr();
  relation r = evaluate(queries.at(i));
  if (r.size() > 0) {
    q += "Yes(" + to_string(r.size()) + ")\n";
  }
  else {
    q += "No\n";
  }
  return q + r.toStr();
}

relation database::evaluate(query q) {
  for (unsigned int j = 0; j < relations.size(); j++){
    if (q.Name() == relations.at(j).Name()) {
      relation toReturn(q.getParams());
      for (int k = 0; k < relations.at(j).size(); k++) {
        if (q.eval(relations.at(j).at(k))) {
          toReturn.addTuple(relations.at(j).at(k).project(q.getProjections()));
        }
      }
      return toReturn;
    }
  }
  cout << "Some kinda error, shouldn't have ever gotten this far in database::evaluate(query q)";
  relation toReturn(q.getParams());
  return toReturn;
}

string database::evaluate() {
  graph graphicus(rules);
  cout << graphicus.ToString() << endl;
  graphicus.findSCC();
  cout << endl << "Rule Evaluation" << endl;
  int totaldifference;
  for (int i = 0; i < graphicus.numSCC(); i++) {
    int passes = 0;
    set<int> scc = graphicus.getSCCAt(i);
    string tmp = "";
    for(set<int>::iterator it = scc.begin(); it != scc.end(); it++) {
      tmp += "R" + to_string(*it) + ",";
    }
    tmp.pop_back();
    cout << "SCC: " << tmp << endl;
    if (scc.size() == 1 && !graphicus.recursiveAt(*scc.begin())) {
      cout << rules.at(*scc.begin()).toStr() << endl;

      getConclusion(*scc.begin());
      passes++;
    }
    else do {
      totaldifference = 0;
      for (unsigned int i = 0; i < relations.size(); i++) {
        totaldifference += relations.at(i).size();
      }
      for(set<int>::iterator it = scc.begin(); it != scc.end(); it++) {
        cout << rules.at(*it).toStr() << endl;
        getConclusion(*it);
      }
      for (unsigned int i = 0; i < relations.size(); i++) {
        totaldifference -= relations.at(i).size();
      }
      passes++;
    } while (totaldifference != 0);
    cout << passes << " passes: " << tmp << endl;
  }
  //cout << endl <<  "Schemes populated after " << passes << " passes through the Rules." << endl;
  cout << endl << "Query Evaluation" << endl;
  string toReturn = "";
  for (unsigned int i = 0; i < queries.size(); i++) {
    toReturn += evaluate(i);
  }
  return toReturn;
}

void database::getConclusion(int i) {
  relation conclusions = evaluate(rules.at(i).premiseAt(0));
  for (int j = 1; j < rules.at(i).size(); ++j) {
    conclusions.join(evaluate(rules.at(i).premiseAt(j)));
  }
  /*
  for each tuple in conclusions
    push_back a tuple into the relation matching conclusionName;
  */
  for (unsigned int j = 0; j < relations.size(); j++){
    if (relations.at(j).Name() == rules.at(i).name()) {

      relation toPrint;
      map<string,int> m;
      vector<int> toProject;
      for (int k = 0; k < conclusions.getHead().size(); ++k) {
        m[conclusions.getHead().at(k)] = k;
      }
      for (int k = 0; k < rules.at(i).Conclusion().size(); k++) {
        toProject.push_back(m[rules.at(i).Conclusion().at(k)]);
      }
      toPrint = conclusions.project(toProject);
      toPrint.setHead(relations.at(j).getHead());
      cout << toPrint.setDifference(relations.at(j)).toStr();     //UNCOMMENT ME FOR FULL PRODUCTION!!!
      relations.at(j).addSet(toPrint);
      break;
    }
  }
}
