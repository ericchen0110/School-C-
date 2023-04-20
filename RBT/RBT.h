#ifndef RBT_H
#define RBT_H
#include <iostream>

using namespace std;

struct node {
  int value;
  char color;
  node* left;
  node* right;
};

class RBT {
 public:
  RBT();
  void insert();
  
 private:
  node* head;
};
#endif
