#include <iostream>
#include <cstring>
#include <vector>
#include "Node.h"
#include "Stack.h"
#include "Queue.h"
#include "BinaryNode.h"

using namespace std;

BinaryNode* intoTree(vector<char>* input_vector, BinaryNode* head);

int main()
{
  //get input
  vector<char> *input_vector = new vector<char>;
  char temp[100];
  for(int i=0; i<100; i++)
    {
      temp[i] = '\0';
    }
  cout << "Please input your expression" << endl;
  cin.get(temp, 100);
  cin.get();
  
  //put everything into the vector
  for(int i=0; i<100; i++)
    {
      if(temp[i] != '\0' && temp[i] != ' ')
	{
	  input_vector->push_back(temp[i]);
	}
    }

  //create output queue
  Queue *output_queue = new Queue();

  //create a stack
  Stack *myStack = new Stack();
  
  //go thru the vector
  for(int i=0; i<input_vector->size(); i++)
    {
      //if is a number, put into queue
      if(isdigit((*input_vector)[i]) != 0)
	{
	  //make the node for the data
	  Node* input_node = new Node();
	  input_node->setContent((*input_vector)[i]);
	  output_queue->enqueue(input_node);//enqueue
	}
      //if an operatoin, put into stack
      else
	{
	  while(myStack->peek() != '(' && )
	    {
	      
	    }
	}
    }

  /*
  //put everything into a binary expression tree
  BinaryNode* head = new BinaryNode();
  head = intoTree(input_vector, head);
  */
  
  return 0;
}

int precedence

/*
BinaryNode* intoTree(vector<char>* input_vector, BinaryNode* head)
{
  for(int i=0; i<input_vector->size(); i++)
    {
      //check for () 
      if((*input_vector)[i] == ')')
	{
	  return head;
	}
      
      if((*input_vector)[i] == '(')
	{
	  //make start and end iterators
	  auto start = input_vector->begin() + i;
	  auto end = input_vector->end();
	  vector<char> *subVector = new vector<char>;//make sub vector
	  copy(start, end, subVector->begin());//copy into the sub vector
	  head = intoTree(subVector, head);
	}

      
    }

  return head;
}
*/
