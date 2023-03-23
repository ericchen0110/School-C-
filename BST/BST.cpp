#include <iostream>
#include "Node.h"
#include "BST.h"

using namespace std;

BST::BST(Node* head)
{
  this->head = head;//set the head of the tree
}

void BST::add(int input)
{
  //make a node for the input int
  Node* newNode = new Node(input);
  addRecur(newNode, head);
}

void BST::addRecur(Node* newNode, Node* parent)
{
  
}

void BST::remove(int input)
{
  
}

void BST::print()
{
  
}

