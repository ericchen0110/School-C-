#ifndef BINARYNODE_H
#define BINARYNODE_H
#include <iostream>

using namespace std;

class BinaryNode {
 public:
  BinaryNode();
  BinaryNode* getLeft();
  BinaryNode* getRight();
  void setLeft(BinaryNode* input);
  void setRight(BinaryNode* input);
  
 private:
  BinaryNode* left;
  BinaryNode* right;
};
#endif
