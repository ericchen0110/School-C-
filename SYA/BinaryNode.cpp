#include <iostream>
#include "BinaryNode.h"

using namespace std;

BinaryNode::BinaryNode()
{
  left = NULL;
  right = NULL;
}

BinaryNode* BinaryNode::getLeft()
{
  return left;
}

BinaryNode* BinaryNode::getRight()
{
  return right;
}

void BinaryNode::setLeft(BinaryNode* input)
{
  left = input;
}

void BinaryNode::setRight(BinaryNode* input)
{
  right = input;
}
