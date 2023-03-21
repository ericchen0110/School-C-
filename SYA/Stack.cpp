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
  //make a new node with this input
  Node* newNode = new Node();
  newNode->setContent(input);

  //put into stack
  if(this->isEmpty())
    {
      header->setNext(newNode);
    }
  else
    {
      newNode->setNext(header->getNext());
      header->setNext(newNode);
    }

  //cout << "in push: " << this->peek() << endl;
}

char Stack::pop()
{
  if(this->isEmpty())
    {
      return '\0';
    }
  else
    {
      char output = header->getNext()->getContent();//set the output char
      Node *temp = header->getNext();
      header->setNext(header->getNext()->getNext());//set the header to point to the next value
      delete temp;//delete the node
      return output;
    }
}

char Stack::peek()
{
  //cout << "in peek: " << header->getNext() << endl;
  
  if(this->isEmpty())
    {
      return '\0';
    }
  else
    {
      return header->getNext()->getContent();
    }
}
