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
      char index = (*input_vector)[i];//set the current char to be a var

      //if is a number, put into queue
      if(isdigit(index))
	{
	  //cout << "1" << endl;
	  Node* input_node = new Node();
	  input_node->setContent(index);
	  output_queue->enqueue(input_node);
	}
      else if(precedence(index) != 0) //check if is an operator
	{
	  //cout << "2" << endl;
	  while(myStack->peek() != '(' && precedence(myStack->peek()) >= precedence(index))
	    {
	      //cout << "in 2: stack peek: " << myStack->peek()
	      output_queue->enqueue2(myStack->pop());
	    }
	  myStack->push(index);
	  //cout << "in 2 " << myStack->peek() << endl;
	}
      else if(index == '(')
	{
	  //cout << "3" << endl;
	  myStack->push(index);
	}
      else if(index == ')')
	{
	  //cout << "4" << endl;
	  while(myStack->peek() != '(')
	    {
	      output_queue->enqueue2(myStack->pop());
	    }
	  if(myStack->peek() == '(')
	    {
	      myStack->pop();
	    }
	}
    }

  while(!myStack->isEmpty())
    {
      output_queue->enqueue2(myStack->pop());
    }

  
      while(!output_queue->isEmpty())
	{
	  //cout << "working" << endl;
	  cout << output_queue->dequeue() << " ";
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
