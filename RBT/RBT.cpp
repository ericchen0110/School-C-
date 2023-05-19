//this is the cpp file of the RBT class

#include <iostream>
#include "RBT.h"

using namespace std;

RBT::RBT()
{
  head = nullptr;
}

void RBT::deleteFun(int num)
{
  node* resultNode = nullptr;
  node* deleteNode = search(head, num, resultNode);

  if(deleteNode == nullptr)
    {//print out message if can't find number
      cout << "This number is not in the tree" << endl;
      return;
    }

  if(deleteNode->color == 'r' && deleteNode->left == nullptr && deleteNode->right == nullptr)
    {
      deleteNodeFun(deleteNode);
    }
  
  //if has one child
  if( (deleteNode->left == nullptr && deleteNode->right != nullptr) || (deleteNode->left != nullptr && deleteNode->right == nullptr))
    {
      if(deleteNode->left != nullptr)
	{//move the left up
	  deleteCheck(deleteNode, deleteNode->left);
	}
      else if(deleteNode->right != nullptr)
	{//move the right up
	  deleteCheck(deleteNode, deleteNode->right);
	}
    }

  //has two childs
  if(deleteNode->left != nullptr && deleteNode->right != nullptr)
    {
      cout << "working 1" << endl;
      node* newNode = rightMost(deleteNode->left);
      deleteNode->value = newNode->value;
      deleteCheck(newNode, newNode->left);
    }
}

node* RBT::rightMost(node* input)
{
  if(input->right == nullptr)
    {
      return input;
    }

  return rightMost(input->right);
}

void RBT::deleteCheck(node* deleteNode, node* newNode)
{
  //pretend the newNode is a black not if it's a nullptr
  node* tempNode = new node;
  if(newNode == nullptr)
    {
      tempNode->color = 'b';
      tempNode->position = 'L';
      tempNode->value = -1;
      tempNode->parent = deleteNode;
      deleteNode->left = tempNode;
    }
  else
    {
      tempNode->color = newNode->color;
      tempNode->position = newNode->position;
      tempNode->value = newNode->value;
      tempNode->parent = newNode->parent;
      newNode->parent->left = tempNode;
    }
    
  
  //deleteNode is red and newNode black
  if(deleteNode->color == 'r' && tempNode->color == 'b')
    {
      cout << "working 2" << endl;
      deleteNodeFun(deleteNode);
      return;
    }
  
  if(deleteNode->color == 'b' && tempNode->color == 'r')
    {
      //deleteNode is black and newNode is red
      deleteNode->value = tempNode->value;
      deleteNodeFun(tempNode);
      return;
    }
  
  if(deleteNode->color == 'b' && tempNode->color == 'b')
    {//both black

      //delete node
      deleteNodeFun(deleteNode);

      deleteFix(tempNode);
    }
}

void RBT::deleteFix(node* newNode)
{
  if(deleteCase1(newNode))
    {
      return;
    }
  
  deleteCase2(newNode);
  deleteCase3(newNode);
}

bool RBT::deleteCase2(node* newNode)
{//sibling is red
  node* parent = newNode->parent;
  if(newNode->position == 'L')
    {
      node* sibling = parent->right;

      if(sibling != nullptr && sibling->color == 'r')
	{//sibling on the right

	  cout << "delete case2, 1" << endl;
	  
	  //change position
	  char oParentP = parent->position;
	  sibling->position = oParentP;

	  if(sibling->left != nullptr)
	    {
	      sibling->left->position = 'R';
	    }

	  //change color
	  switchColor(parent);
	  switchColor(sibling);

	  //change pointers
	  sibling->parent = parent->parent;
	  if(oParentP == 'L')
	    {
	      parent->parent->left = sibling;
	    }
	  else if(oParentP == 'R')
	    {
	      parent->parent->right = sibling;
	    }
	  parent->parent = sibling;
	  parent->right = sibling->left;

	  if(sibling->left != nullptr)
	    {
	      sibling->left->parent = parent;
	    }

	  sibling->left = parent;

	  //call case 3
	  //deleteCase3(newNode);
	  
	  return true;
	}
    }
  else if(newNode->position == 'R')
    {
      node* sibling = parent->left;
	
      if(sibling != nullptr && sibling->color == 'r')
	{//sibling on the left

	  cout << "delete case2, 2" << endl;
	  
	  //change position
	  char oParentP = parent->position;
	  sibling->position = oParentP;

	  if(sibling->right != nullptr)
	    {
	      sibling->right->position = 'L';
	    }

	  //change color
	  switchColor(parent);
	  switchColor(sibling);

	  //change pointers
	  sibling->parent = parent->parent;
	  if(oParentP == 'L')
	    {
	      parent->parent->left = sibling;
	    }
	  else if(oParentP == 'R')
	    {
	      parent->parent->right = sibling;
	    }
	  parent->parent = sibling;
	  parent->left = sibling->right;

	  if(sibling->right != nullptr)
	    {
	      sibling->right->parent = parent;
	    }

	  sibling->right = parent;

	  //call case 3
	  //deleteCase3(newNode);
	  
	  return true;
	}
    }

  return false;
}

bool RBT::deleteCase3(node* newNode)
{//sibling is black

  node* parent = newNode->parent;

  if(newNode->position == 'L' && parent->right->color == 'b')
    {//sibling is black
      cout << "delete case 3, 1" << endl;
      
      node* sibling = parent->right;
      sibling->color = 'r';
      if(newNode->value == -1)
	{
	  newNode = nullptr;
	}
      deleteFix(parent);
      return true;
    }
  else if(newNode->position == 'R' && parent->left->color == 'b')
    {//sibling is black
      cout << "delete case 3, 2" << endl;
      
      node* sibling = parent->left;
      sibling->color = 'r';
      if(newNode->value == -1)
	{
	  newNode = nullptr;
	}
      deleteFix(parent);
      return true;
    }

  return false;
}

bool RBT::deleteCase1(node* newNode)
{
  //if deleteNode is head
  if(head == newNode)
    {
      return true;
    }
  else
    {
      return false;
    }
}

void RBT::deleteNodeFun(node* input)
{

  cout << "working 3" << endl;
  
  node* parent = input->parent;
  node* leftC = input->left;
  node* rightC = input->right;

  if(rightC == nullptr && leftC == nullptr)
    {
      if(input->position == 'L')
	{
	  parent->left = nullptr;
	}
      else if(input->position == 'R')
	{
	  parent->right = nullptr;
	}
    }
  else if(rightC == nullptr)
    {//move left up
      if(input->position == 'L')
	{
	  parent->left = leftC;
	}
      else if(input->position == 'R')
	{
	  parent->right = leftC;
	  leftC->position = 'R';
	}
      leftC->parent = parent;
    }
  else if(leftC == nullptr)
    {//move right up
      if(input->position == 'R')
	{
	  parent->right = rightC;
	}
      else if(input->position == 'L')
	{
	  parent->left = rightC;
	  rightC->position = 'L';
	}
      rightC->parent = parent;
    }
  delete input;
}

void RBT::searchFun(int num)
{
  node* resultNode = nullptr;
  if(search(head, num, resultNode) == nullptr)
    {
      cout << "This number isn't in the tree." << endl;
    }
  else
    {
      cout << "This number is in the tree." << endl;
    }
}

node* RBT::search(node* header, int num, node* result)
{
  if(header == nullptr)
    {//return null if number isn't in the tree
      return header;
    }

  if(header->value == num)
    {//return the pointer of the header
      return header;
    }

  //if number bigger than current
  if(num > header->value)
    {
      result = search(header->right, num, result);
    }
  else
    {
      result = search(header->left, num, result);
    }

  return result;
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
	  cout << "case2" << endl;
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

	  //change position
	  newNode->position = 'L';
	  newNode->parent->position = 'L';
	  
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

	  //change position
	  newNode->position = 'R';
	  newNode->parent->position = 'R';
	  
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
