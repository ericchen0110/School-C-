#include <iostream>
#include "Node.h"
#include "Stack.h"

using namespace std;

Stack::Stack()
{
  header->setNext(NULL);
  BinaryHeader->setLeft(NULL);
  BinaryHeader->setRight(NULL);
}

bool Stack::isEmpty()
{//return true if stack empty, false if not
  if(header->getNext() == NULL)
    {
      return true;
    }
  else
    {
      return false;
    }
}

void Stack::push(BinaryNode* input)
{
  BinaryNode* newNode = new BinaryNode();//make a new node pointer to store in stack
  newNode->setLeft(input);//point to the input node
  
  if(BinaryHeader->getRight() == NULL)
    {//set the header to point at the new node if the stack is empty
      BinaryHeader->setRight(newNode);
    }
  else
    {
      newNode->setRight(BinaryHeader->getRight());//point new node to the first node in stack
      BinaryHeader->setRight(newNode);//point header to the new node
    }
}

BinaryNode* Stack::BinaryPop()
{
  BinaryNode* output = this->BinaryPeek();//store the output in a var
  if(BinaryHeader->getRight()->getRight() == NULL)
    {
      delete BinaryHeader->getRight();
      BinaryHeader == NULL;
    }
  else
    {
      BinaryNode* temp = BinaryHeader->getRight();
      BinaryHeader->setRight(BinaryHeader->getRight()->getRight());
      delete temp;
    }
  
  return output;
}

BinaryNode* Stack::BinaryPeek()
{
  if(BinaryHeader->getRight() == NULL)
    {//check if the stack is empty
      cout << "stack is empty!" << endl;
      return NULL;
    }
  else
    {
      //cout << BinaryHeader->getRight()->getLeft()->getContent();
      return BinaryHeader->getRight()->getLeft();//return the node that the first node in the stack points to
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
      char output = this->peek();//set the output char
      Node *temp = header->getNext();
      if(header->getNext()->getNext() == NULL)
	{
	  header->setNext(NULL);
	}
      else
	{
	  header->setNext(header->getNext()->getNext());//set the header to point to the next value
	}
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
