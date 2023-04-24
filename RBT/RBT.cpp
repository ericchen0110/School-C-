#include <iostream>
#include "RBT.h"

using namespace std;

RBT::RBT()
{
  head = nullptr;
}

void RBT::insert(int num)
{
  //make a node
  node* newNode = new node;
  newNode->value = num;
  newNode->color = 'r';
  newNode->left = nullptr;
  newNode->right = nullptr;

  //if this is the node
  if(head == nullptr)
    {
      head = newNode;
    }

  //if adding to the head
  if(head->left == nullptr && head->right == nullptr)
    {
      head->color = 'b';//change the color to black
      if(addRight(head->value, newNode->value))
	{//add to the right of the head if the value is greater than the head
	  head->right = newNode;
	}
      else
	{//add to left if otherwise
	  head->left = newNode;
	}
    }

  
}

bool RBT::addRight(int num1, int num2)
{
  if(num1 < num2)
    {
      return true;
    }
  else
    {
      return false;
    }
}

void RBT::print()
{
  printRecur(head, 0);
}

void RBT::printRecur(node* header, int space)
{
  if(header == nullptr)
    {//if the header is null, return
      return;
    }

  space += 4;
  printRecur(header->right, space);//print out right side
  cout << "header right: " << head->right << endl;
  cout << endl;
  for(int i=4; i<space; i++)
    {//print out the spacing
      cout << " ";
    }
  cout << header->value << endl;//print out the number
  printRecur(header->left, space);//print out left side
}
