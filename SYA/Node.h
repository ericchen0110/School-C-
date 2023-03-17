#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <cstring>

using namespace std;

class Node {
 public:
  Node();
  ~Node();
  char getContent();
  Node* getNext();
  void setContent(char input);
  void setNext(Node* input);
  
 private:
  char content;
  Node* next;
};

#endif

