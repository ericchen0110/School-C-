#include <iostream>
#include "Node.h"

using namespace std;

Node::Node()
{
  content = '\0';
  next = NULL;
}

Node::~Node()
{
  
}

char Node::getContent()
{
  return content;
}

Node* Node::getNext()
{
  return next;
}

void Node::setContent(char input)
{
  content = input;
}

void Node::setNext(Node* input)
{
  next = input;
}
