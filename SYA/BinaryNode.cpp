#include <iostream>
#include "BinaryNode.h"

using namespace std;

BinaryNode::BinaryNode()
{
  content = '\0';
  left = NULL;
  right = NULL;
}

void BinaryNode::setContent(char input)
{
  content = input;
}

char BinaryNode::getContent()
{
  return content;
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
