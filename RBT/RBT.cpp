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
  newNode->position = '\0';
  newNode->left = nullptr;
  newNode->right = nullptr;
  newNode->parent = nullptr;
  
  //if this is the node
  if(head == nullptr)
    {
      head = newNode;
      return;
    }

  //if adding to the head
  if(head->left == nullptr && head->right == nullptr)
    {
      head->color = 'b';//change the color to black
      if(addRight(head->value, newNode->value))
	{//add to the right of the head if the value is greater than the head
	  head->right = newNode;
	  newNode->position = 'R';
	}
      else
	{//add to left if otherwise
	  head->left = newNode;
	  newNode->position = 'L';
	}
      newNode->parent = newNode;
      return;
    }

  //add normally if otherwise
  add(newNode, head);

  if(newNode->parent != nullptr && newNode->parent->parent != nullptr)
    {
      node* grandparent = newNode->parent->parent;//define grandparent
      
      //case 3: parent and uncle are red
      case3(newNode, grandparent);
    }
}

void RBT::case3(node* newNode, node* grandparent)
{
  if(newNode->color == 'r' && grandparent->left->color == 'r' && grandparent->right->color == 'r')
    {
      //set parent and uncle to black
      if
    }
  else
    {
      return;
    }
}

void RBT::add(node* newNode, node* header)
{
  //determine right or left
  if(addRight(header->value, newNode->value))
    {//check right
      if(header->right == nullptr)
	{//add to right
	  header->right = newNode;
	  newNode->parent = header;
	  newNode->position = 'R';
	}
      else
	{
	  add(newNode, header->right);
	}
    }
  else
    {//check left
      if(header->left == nullptr)
	{//add to left
	  header->left = newNode;
	  newNode->parent = header;
	  newNode->position = 'L';
	}
      else
	{
	  add(newNode, header->left);
	}
    }
}

bool RBT::addRight(int parent, int child)
{
  if(child > parent)
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

  cout << endl;
  for(int i=4; i<space; i++)
    {//print out the spacing
      cout << " ";
    }
  cout << header->value << endl;//print out the number
  printRecur(header->left, space);//print out left side
}
