#include <iostream>
#include "Node.h"

using namespace std;

Node::Node()
{
  content = NULL;
  next = NULL;
}

char* Node::getContent()
{
  return content;
}

Node* Node::getNext()
{
  return next;
}

void Node::setContent(char* input)
{
  strcpy(content, input);
}

void Node::setNext(Node* input)
{
  next = input;
}
