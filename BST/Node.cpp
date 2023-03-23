#include <iostream>
#include "Node.h"

using namespace std;

Node::Node(int value)
{
  //set left and right to null
  left = nullptr;
  right = nullptr;
  this->value = value;//set the value to the input
}

Node::~Node()
{
  
}

int Node::getValue()
{
  return value;
}

void Node::setLeft(Node* input)
{
  left = input;
}

void Node::setRight(Node* input)
{
  right = input;
}

Node* Node::getLeft()
{
  return left;
}

Node* Node::getRight()
{
  return right;
}
