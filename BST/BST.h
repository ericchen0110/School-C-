#ifndef BST_H
#define BST_H
#include <iostream>
#include "Node.h"

using namespace std;

class BST {
 public:
  BST(Node* head);
  void add(int input);
  void addRecur(Node* newNode, Node* parent);
  void remove(int input);
  void print();
  
 private:
  Node* head;
};
#endif
