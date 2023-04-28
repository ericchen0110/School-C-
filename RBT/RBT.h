#ifndef RBT_H
#define RBT_H
#include <iostream>

using namespace std;

struct node {
  int value;
  char color;
  char position;
  node* left;
  node* right;
  node* parent;
};

class RBT {
 public:
  RBT();
  void insert(int num);
  void print();
  
 private:
  void add(node* newNode, node* header);
  bool addRight(int parent, int child);
  void printRecur(node* header, int space);
  void fix(node* newNode);
  void case3(node* newNode, node* grandparent);
  void case4(node* newNode, node* grandparent);
  void case5(node* newNode, node* grandparent);
  void switchColor(node* newNode);
  
  node* head;
};
#endif
