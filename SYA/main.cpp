#include <iostream>
#include <cstring>
#include <vector>
#include "Node.h"
#include "Stack.h"
#include "Queue.h"
#include "BinaryNode.h"

using namespace std;

int precedence(char input);

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
      cout << "beginning " << i << myStack->peek() << endl;
      //if is a number, put into queue
      if(isdigit((*input_vector)[i]))
	{
	  cout << "1" << endl;
	  //make the node for the data
	  Node* input_node = new Node();
	  input_node->setContent((*input_vector)[i]);
	  output_queue->enqueue(input_node);//enqueue
	}
      //if left parenthesis
      else if((*input_vector)[i] == '(')
	{
	  cout << "2" << endl;
	  myStack->push((*input_vector)[i]);
	}
      //if right parenthesis
      else if((*input_vector)[i] == ')')
	{
	  cout << "3" << endl;
	  cout << "top of stack: " << myStack->peek() << endl;
	  while(myStack->peek() != '(')
	    {
	      output_queue->enqueue(myStack->pop());
	    }
	}
      //if an operatoin, put into stack
      else
	{
	  cout << "4" << endl;
	  while(myStack->peek() != '(' && precedence(myStack->peek()) >= precedence((*input_vector)[i]))
	    {
	      output_queue->enqueue(myStack->pop());
	      myStack->push((*input_vector)[i]);
	    }
	}
      
      //keep popping the rest of the stack into the queue
      while(!myStack->isEmpty())
	{
	  output_queue->enqueue(myStack->pop());
	}

      //cout << "top of stack: " << myStack->peek() << endl;
      
    }
  
  return 0;
}

//return the precedence of the input operation
int precedence(char input)
{
  switch(input)
    {
    case '+': case '-':
      return 1;
      break;

    case '*': case '/':
      return 2;
      break;

    case '^':
      return 3;
      break;

    default:
      return 0;
    }
}
