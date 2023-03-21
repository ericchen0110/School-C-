#include <iostream>
#include "Queue.h"
#include "Node.h"

using namespace std;

Queue::Queue()
{
  head->setNext(NULL);
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
      head->setNext(input);//set the head to point to the new node
    }
  else
    {//when the queue isn't empty
      Node* temp = head;//make a temp node pointer pointing to the same thing as head
      while (temp->getNext() != NULL)
	{
	  temp = temp->getNext();//find the last node in the queue
	}
      temp->setNext(input);//set the last node to point to the new node
    }
}

void Queue::enqueue(char input)
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
      Node* temp = head;
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

