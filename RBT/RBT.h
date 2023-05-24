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
  void deleteFun(int num);
  node* search(node* header, int num, node* result);
  void searchFun(int num);
  
 private:
  void add(node* newNode, node* header);
  bool addRight(int parent, int child);
  void printRecur(node* header, int space);
  void fix(node* newNode);
  void case3(node* newNode, node* grandparent);
  void case4(node* newNode, node* grandparent);
  void case5(node* newNode, node* grandparent);
  void switchColor(node* newNode);
  node* rightMost(node* input);

  void deleteCheck(node* deleteNode, node* newNode);
  void deleteFix(node* newNode);
  bool deleteCase1(node* newNode);
  bool deleteCase2(node* newNode);
  bool deleteCase3(node* newNode);
  
  void deleteNodeFun(node* input);

  void leftRotate(node* input);
  void rightRotate(node* input);

  
  node* head;
};
#endif
