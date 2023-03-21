#ifndef STACK_H
#define STACK_H
#include <iostream>
#include "Node.h"
#include "BinaryNode.h"

using namespace std;

class Stack {
 public:
  Stack();
  void push(char input);
  char pop();
  char peek();

  void push(BinaryNode* input);
  char BinaryPop();
  
  bool isEmpty();

 private:
  Node *header = new Node();
  BinaryNode *BinaryHeader = new BinaryNode();
};
#endif
