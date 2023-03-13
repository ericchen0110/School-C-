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
      temp[i] = '#';
    }
  cout << "Please input your expression" << endl;
  cin.get(temp, 100);
  cin.get();

  //put everything into the vector
  for(int i=0; i<100; i++)
    {
      if(temp[i] != '#')
	{
	  input_vector->push_back(temp[i]);
	}
    }
  
  //put everything into a binary expression tree
  BinaryNode* head = new BinaryNode();
  head = intoTree(input_vector, head);
  
  return 0;
}

BinaryNode* intoTree(vector<char>* input_vector, BinaryNode* head)
{
  for(int i=0; i<input_vector->size(); i++)
    {
      if((*input_vector)[i] == ')')
	{
	  return head;
	}
      
      if((*input_vector)[i] == '(')
	{
	  vector<char>::const_iterator first = input_vector->begin() + i;
	  vector<char>::const_iterator last = input_vector->end();
	  vector<char> *subVector(first, last);
	  head = intoTree(subVector, head);
	}
    }

  return head;
}
