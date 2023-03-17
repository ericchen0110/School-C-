#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include "Node.h"

using namespace std;

class Queue{
 public:
  Queue();
  void enqueue(Node* input);
  char dequeue();
  bool isEmpty();
  
 private:
  Node* head = new Node();
  Node* tail = new Node();
};
#endif
