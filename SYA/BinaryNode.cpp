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

char BinaryNode::getLeft()
{
  return left->getContent();
}

char BinaryNode::getRight()
{
  return right->getContent();
}

void BinaryNode::setLeft(BinaryNode* input)
{
  left = input;
}

void BinaryNode::setRight(BinaryNode* input)
{
  right = input;
}
