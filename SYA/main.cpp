/*this is the main file of the Shunting Yard Algorithm
  Written by Eric Chen
  Date: 3/21
*/

#include <iostream>
#include <cstring>
#include <vector>
#include "Node.h"
#include "Stack.h"
#include "Queue.h"
#include "BinaryNode.h"

using namespace std;

int precedence(char input);
void infix(BinaryNode* tree);
void prefix(BinaryNode* tree);
void postfix(BinaryNode* tree);

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
	  Node* input_node = new Node();//make the node to put into the queue
	  input_node->setContent(index);
	  output_queue->enqueue(input_node);
	}
      else if(precedence(index) != 0) //check if is an operator
	{
	  while(!myStack->isEmpty() && myStack->peek() != '(' && precedence(myStack->peek()) >= precedence(index))
	    {
	      output_queue->enqueue(myStack->pop());//pop from the stack and put into queue
	    }
	  myStack->push(index);//push into stack
	}
      else if(index == '(')
	{
	  myStack->push(index);//push into stack
	}
      else if(index == ')')
	{
	  while(myStack->peek() != '(')
	    {
	      output_queue->enqueue(myStack->pop());//pop from stack and then put into queue
	    }
	  if(myStack->peek() == '(')
	    {
	      myStack->pop();//pop the ( out
	    }
	}
    }

  while(!myStack->isEmpty())
    {
      output_queue->enqueue(myStack->pop());//put the rest of the chars in the stack into the queue
    }

  //construct an expression tree
  Stack *BinaryStack = new Stack();//make a new stack
  
  //go thru the output queue
  while(!output_queue->isEmpty())
    {
      //make a binary node for each char
      BinaryNode *newNode = new BinaryNode();
      newNode->setContent(output_queue->dequeue());

      if(isdigit(newNode->getContent()))//if the char is a number
	{
	  BinaryStack->push(newNode);//push the node into the stack
	}
      else
	{
	  newNode->setRight(BinaryStack->BinaryPop());//set the node's right pointer to be the last node in stack
	  newNode->setLeft(BinaryStack->BinaryPop());//set the node's left pointer to be the second last node in stack
	  BinaryStack->push(newNode);//push the node into the stack
	}
    }
  

  while(true)
    {
      //ask the user which fix do they want
      cout << "Do you want to diplay in Infix, Prefix, or Postfix?" << endl;
      cout << "Type \"Quit\" if you would like to quit" << endl;
      char inputChar[100];
      cin >> inputChar;

      if(strcmp(inputChar, "Infix") == 0)
	{
	  //infix
	  infix(BinaryStack->BinaryPeek());
	}
      else if(strcmp(inputChar, "Prefix") == 0)
	{
	  //prefix
	  prefix(BinaryStack->BinaryPeek());
	}
      else if(strcmp(inputChar, "Postfix") == 0)
	{
	  //postfix
	  postfix(BinaryStack->BinaryPeek());
	}
      else if(strcmp(inputChar, "Quit") == 0)
	{
	  break;
	}
      cout << "\n\n";
    } 
  
  return 0;
}

void prefix(BinaryNode* tree)
{
  //print char
  cout << tree->getContent() << " ";
  if(tree->getLeft() != NULL)
    {//print left
      prefix(tree->getLeft());
    }
  if(tree->getRight() != NULL)
    {//print right
      prefix(tree->getRight());
    }
}

void postfix(BinaryNode* tree)
{
  if(tree->getLeft() != NULL)
    {//print left
      postfix(tree->getLeft());
    }
  if(tree->getRight() != NULL)
    {//print right
      postfix(tree->getRight());
    }
  //print char
  cout << tree->getContent() << " ";
}

void infix(BinaryNode* tree)
{
  if(precedence(tree->getContent()) != 0)
    {//if content is an operator
      cout << "( ";
    }
  if(tree->getLeft() != NULL)
    {//print out left side
      infix(tree->getLeft());
    }
  cout << tree->getContent() << " ";
  if(tree->getRight() != NULL)
    {//right side
      infix(tree->getRight());
    }
  if(precedence(tree->getContent()) != 0)
    {
      cout << ") ";
    }
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
