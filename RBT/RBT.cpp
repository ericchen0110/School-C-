//this is the cpp file of the RBT class

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
  
  //add
  add(newNode, head);

  //fix
  fix(newNode);
}

void RBT::fix(node* newNode)
{
  //case1
  if(newNode == head)
    {
      newNode->color = 'b';
    }
  
  if(newNode->parent != nullptr && newNode->parent->parent != nullptr)
    {
      node* grandparent = newNode->parent->parent;//define grandparent

      //check case 2, parent is black
      if(newNode->parent->color == 'b')
	{
	  //cout << "case2" << endl;
	  return;
	}
      
      //check case 3, parent and uncle are red
      case3(newNode, grandparent);

      //check case 4
      case4(newNode, grandparent);

      //check case 5
      case5(newNode, grandparent);
    }
}

void RBT::case4(node* newNode, node* grandparent)
{
  if(newNode->parent->color == 'r')
    {
      if( (grandparent->right == nullptr || grandparent->right->color == 'b') && newNode->parent->position == 'L' && newNode->position == 'R')
	{//parent is left, new node is right

	  //cout << "case4 1" << endl;

	  char tPosition = newNode->position;
	  newNode->position = newNode->parent->position;
	  newNode->parent->position = tPosition;
	  
	  //change parent node
	  newNode->parent->parent = newNode;//change parent's parent to new node
	  newNode->parent->right = newNode->left;
	  
	  
	  //change new node
	  newNode->left = newNode->parent;//change new node left to the parent
	  newNode->parent = grandparent;//change parent pointer to grandparent
	  grandparent->left = newNode;//change grandparent to point to new node
	  case5(newNode->left, newNode->parent);//call case5
	}
      else if( (grandparent->left == nullptr || grandparent->left->color == 'b') && newNode->parent->position == 'R' && newNode->position == 'L')
	{//parent is right, new node is left

	  //cout << "case4 2" << endl;

	  char tPosition = newNode->position;
	  newNode->position = newNode->parent->position;
	  newNode->parent->position = tPosition;
	  
	  //change the parent node
	  newNode->parent->parent = newNode;
	  newNode->parent->left = newNode->right;

	  //change new node
	  newNode->right = newNode->parent;
	  newNode->parent = grandparent;
	  grandparent->right = newNode;

	  case5(newNode->right, newNode->parent);
	}
    }
}

void RBT::case5(node* newNode, node* grandparent)
{
  if(newNode->parent->color == 'r')
    {
      if( (grandparent->right == nullptr || grandparent->right->color == 'b') && newNode->parent->position == 'L' && newNode->position == 'L')
	{//parent is left and node is left

	  //cout << "case5 1" << endl;

	  //change position
	  char oGrandparentP = grandparent->position;

	  grandparent->position = 'R';
	  newNode->parent->position = oGrandparentP;
      
	  //change color
	  switchColor(newNode->parent);
	  switchColor(grandparent);

	  grandparent->left = newNode->parent->right;//1
	  newNode->parent->parent = grandparent->parent;//4

	  if(grandparent->left != nullptr)
	    {
	      grandparent->left->parent = grandparent;//5
	      grandparent->left->position = 'L';
	    }

	  if(grandparent == head)
	    {
	      head = newNode->parent;
	    }
	  else
	    {
	      if(oGrandparentP == 'R')
		{
		  grandparent->parent->right = newNode->parent;
		}
	      else if(oGrandparentP == 'L')
		{
		  grandparent->parent->left = newNode->parent;
		}
	    }
      
	  grandparent->parent = newNode->parent;//2
	  newNode->parent->right = grandparent;//3
      
	}
      else if( (grandparent->left == nullptr || grandparent->left->color == 'b') && newNode->parent->position == 'R' && newNode->position == 'R')
	{//parent is right and node is right

	  //cout << "case5 2" << endl;
      
	  //change color
	  switchColor(newNode->parent);
	  switchColor(grandparent);

	  //change position
	  char oGrandparentP = grandparent->position;

	  newNode->parent->position = oGrandparentP;
	  grandparent->position = 'L';

	  grandparent->right = newNode->parent->left;//1
	  newNode->parent->parent = grandparent->parent;//4

	  if(grandparent->right != nullptr)
	    {
	      grandparent->right->parent = grandparent;//5
	      grandparent->right->position = 'R';
	    }

	  if(grandparent == head)
	    {
	      head = newNode->parent;
	    }
	  else
	    {
	      if(oGrandparentP == 'R')
		{
		  grandparent->parent->right = newNode->parent;
		}
	      else if(oGrandparentP == 'L')
		{
		  grandparent->parent->left = newNode->parent;
		}
	    }
      
	  grandparent->parent = newNode->parent;//2
	  newNode->parent->left = grandparent;//3      
						  }
    }
}

void RBT::switchColor(node* newNode)
{
  if(newNode->color == 'r')
    {
      newNode->color = 'b';
    }
  else if(newNode->color == 'b')
    {
      newNode->color = 'r';
    }
}

void RBT::case3(node* newNode, node* grandparent)
{
  if(grandparent->left != nullptr && grandparent->right != nullptr)
    {
      if(newNode->color == 'r' && grandparent->left->color == 'r' && grandparent->right->color == 'r')
	{
	  //set parent and uncle to black

	  //cout << "case3" << endl;
	
	  grandparent->left->color = 'b';
	  grandparent->right->color = 'b';
	  grandparent->color = 'r';//set grandparent to red

	  fix(grandparent);//check grandparent
	}
      else
	{
	  return;
	}
    }
}

void RBT::add(node* newNode, node* header)
{
  //case 1: if this is the head
  if(head == nullptr)
    {
      head = newNode;
      head->color = 'b';//change into black node
      return;
    }
  
  //determine right or left
  if(addRight(header->value, newNode->value))
    {//check right
      if(header->right == nullptr)
	{//add to right
	  //cout << "add right" << endl;
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
	  //cout << "add left" << endl;
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

  space += 8;
  printRecur(header->right, space);//print out right side

  cout << endl;
  for(int i=4; i<space; i++)
    {//print out the spacing
      cout << " ";
    }
  cout << header->value << ", " << header->color << endl;//print out the number & color
  printRecur(header->left, space);//print out left side
}
