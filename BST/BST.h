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
  void addRecur2(Node* parent);
  void remove(int input);
  void removeRecur(Node* parent, int input);
  void print(Node* header, int space);
  void print1();
  void search(int input);
  void searchRecur(Node* parent, int input);
  
 private:
  Node* head;
};
#endif
