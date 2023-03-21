#ifndef BINARYNODE_H
#define BINARYNODE_H
#include <iostream>

using namespace std;

class BinaryNode {
 public:
  BinaryNode();
  void setContent(char input);
  char getContent();
  char getLeft();
  char getRight();
  void setLeft(BinaryNode* input);
  void setRight(BinaryNode* input);
  
 private:
  char content;
  BinaryNode* left;
  BinaryNode* right;
};
#endif
