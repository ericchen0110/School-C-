#include <iostream>
#include "Queue.h"
#include "Node.h"

using namespace std;

Queue::Queue()
{
  head->setNext(NULL);
  tail->setNext(NULL);
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
  tail->getNext()->setNext(input);//put the input at the end of the queue

  tail->setNext(tail->getNext());//set the tail pointer to point to the new node
}

char* Queue::dequeue()
{
  //check if queue is empty
  if(this->isEmpty())
    {
      return NULL;
    }
  
  //make a variable to store the output
  char* output = head->getNext()->getContent();

  //make a temp node pointer pointing to the head
  Node* temp;
  temp->setNext(head->getNext());

  //set the header to next node
  if(head->getNext()->getNext() == NULL)
    {
      head->setNext(NULL);
    }
  else
    {
      head->setNext(head->getNext()->getNext());
    }

  delete temp->getNext();//delete the node

  return output;//return the output
}


