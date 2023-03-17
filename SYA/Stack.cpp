#include <iostream>
#include "Node.h"
#include "Stack.h"

using namespace std;

Stack::Stack()
{
  header->setNext(NULL);
}

bool Stack::isEmpty()
{
  if(header->getNext() == NULL)
    {
      return true;
    }
  else
    {
      return false;
    }
}

void Stack::push(char input)
{
  //make a node with this input
  Node* newNode = new Node();
  newNode->setContent(input);
  newNode->setNext(NULL);

  //put it into the stack
  recur(header)->setNext(newNode);
}

Node* Stack::recur(Node* input_header)
{
  //check if at the end
  if(input_header->getNext() == NULL)
    {
      return input_header;
    }

  return recur(input_header->getNext());
}

char Stack::pop()
{
  char output = recur(header)->getContent();
  deleteFun(recur(header));
  return output;
}

void Stack::deleteFun(Node* input_node)
{
  //delete the content in the node
  delete (delete_recur(header)->getNext());

  //set the previous pointer to NULL
  delete_recur(header)->setNext(NULL);
}

Node* Stack::delete_recur(Node* input_header)
{
  //check if next next node is null
  if(input_header->getNext()->getNext() == NULL)
    {
      return input_header;
    }

  return delete_recur(input_header->getNext());
}

char Stack::peek()
{
  //check if empty
  if(this->isEmpty())
    {
      return '\0';
    }
  
  return recur(header)->getContent();
}
