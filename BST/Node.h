#ifndef NODE_H
#define NODE_H
#include <iostream>

using namespace std;

class Node {
 public:
  Node(int value);
  ~Node();
  int getValue();
  void setLeft(Node* input);
  void setRight(Node* input);
  Node* getLeft();
  Node* getRight();
  
 private:
  int value;
  Node* left;
  Node* right;
};
#endif
