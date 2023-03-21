#include <iostream>
#include "Queue.h"
#include "Node.h"

using namespace std;

Queue::Queue()
{
  head->setNext(NULL);
  //tail->setNext(NULL);
}

bool Queue::isEmpty()
{
  if(head->getNext() == NULL)
    {
      return true;
    }
  else
    {
      return false;
    }
}

void Queue::enqueue(Node* input)
{
  if(this->isEmpty())
    {
      head->setNext(input);
    }
  else
    {
      Node* temp = head;
      while (temp->getNext() != NULL)
	{
	  temp = temp->getNext();
	}
      temp->setNext(input);
    }
}

void Queue::enqueue2(char input)
{
  //make a new node
  Node *newNode = new Node();
  newNode->setContent(input);

  //do the same thing as the other enqueue
  if(this->isEmpty())
    {
      head->setNext(newNode);
    }
  else
    {
      Node* temp = newNode;
      while(temp->getNext() != NULL)
	{
	  temp = temp->getNext();
	}
      temp->setNext(newNode);
    }
}

char Queue::dequeue()
{
  //check if the queue is empty
  if(this->isEmpty())
    {
      cout << "This queue is empty" << endl;
      return '\0';
    }
  else
    {
      Node* temp = head;
      char output = temp->getNext()->getContent();
      head = head->getNext();
      delete temp;
      return output;
    }
}


/*
void Queue::enqueue(Node* input)
{
  //check if the queue is empty
  if(this->isEmpty())
    {
      tail->setNext(input);
      head->setNext(input);
    }
  else
    {
      tail->getNext()->setNext(input);//put the input at the end of the queue
      tail->setNext(tail->getNext());//set the tail pointer to point to the new node
    }

  //cout << "in enqueue 1 working: " << this->dequeue() << endl;
}

void Queue::enqueue(char input)
{
  //make a node
  Node *newNode = new Node();
  newNode->setContent(input);

  //check if the queue is empty
  if(this->isEmpty())
    {
      tail->setNext(newNode);
      head->setNext(newNode);
    }
  else
    {
      tail->getNext()->setNext(newNode);
      tail->setNext(tail->getNext());
    }

  //cout << "in enqueue 2 working: " << this->dequeue() << endl;
}

char Queue::dequeue()
{
  //check if queue is empty
  if(this->isEmpty())
    {
      return '\0';
    }
  
  //make a variable to store the output
  char output = head->getNext()->getContent();

  //make a temp node pointer pointing to the head
  Node* temp;
  temp->setNext(head->getNext());

  //set the header to next node
  if(head->getNext()->getNext() == NULL)
    {
      head->setNext(NULL);
      tail->setNext(NULL);
    }
  else
    {
      head->setNext(head->getNext()->getNext());
    }

  delete temp->getNext();//delete the node

  return output;//return the output
}


*/
