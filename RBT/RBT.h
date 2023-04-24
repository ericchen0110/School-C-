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
  void insert(int num);
  void print();
  
 private:
  bool addRight(int num1, int num2);
  void printRecur(node* header, int space);
  node* head;
};
#endif
