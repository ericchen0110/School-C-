#ifndef STACK_H
#define STACK_H
#include <iostream>
#include "Node.h"

using namespace std;

class Stack {
 public:
  Stack();
  void push(char* input);
  char* pop();
  char* peek();

 private:
  Node *header = new Node();
  Node* recur(Node* input_header);
  void deleteFun(Node* input_node);
  void delete_recur(Node* input_header);
};
#endif
