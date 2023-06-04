#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <vector>

using namespace std;

struct pair {
  char letter;
  int number;
};

class Graph {
 public:
  Graph();
  void addVertex(char input);
  void addEdge(char A, char B, int weight);
  void removeVertex(char input);
  void removeEdge(char A, char B);
  void shortPath(char A, char B);

  void printFun();
  
 private:
  vector<vector<int>> *numTable;
  vector<char> *charVec;
};
#endif
