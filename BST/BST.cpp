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
  //check greater or smaller than parent
  if(newNode->getValue() < parent->getValue())
    {//put into left pointer
      if(parent->getLeft() == nullptr)
	{//set the left to new node if empty
	  parent->setLeft(newNode);
	  return;
	}
      else
	{//keep going
	  addRecur(newNode, parent->getLeft());
	}
    }
  else
    {//put into right pointer and do the same thing
      if(parent->getRight() == nullptr)
	{
	  parent->setRight(newNode);
	  return;
	}
      else
	{
	  addRecur(newNode, parent->getRight());
	}
    }
}

void BST::remove(int input)
{
  removeRecur(head, input);
}

void BST::addRecur2(Node* parent)
{
  if(parent == nullptr)
    {//stop adding if reaching the end
      return;
    }

  this->add(parent->getValue());//add the parent's value to the tree
  addRecur2(parent->getLeft());//add left
  addRecur2(parent->getRight());//add right
}

void BST::removeRecur(Node* parent, int input)
{
  if(parent == nullptr)
    {//if the number is not in the tree, return
      cout << "This number is not in the tree" << endl;
      return;
    }

  if(parent->getValue() == input)
    {//delete the node if parent is equal to input
      Node* tempHead = parent;//make a temp node
      //delete the parent node
      delete parent;

      //add the childs to the tree
      addRecur2(tempHead);
      
      return;
    }

  //check if the value if greater or smaller than the parent
  if(input < parent->getValue())
    {
      //check if left is equal to the input
      if(parent->getLeft() != nullptr && parent->getLeft()->getValue() == input)
	{
	  Node* temp = parent->getLeft();//set temp node to equal to parent's left
	  parent->setLeft(nullptr);//set parent left to null
	  addRecur2(temp->getLeft());//add the numbers on left to the tree again
	  addRecur2(temp->getRight());//add right
	  delete temp;//delete
	  return;
	}
      removeRecur(parent->getLeft(), input);//left if smaller
    }
  else
    {//same as above
      if(parent->getRight() != nullptr && parent->getRight()->getValue() == input)
	{
	  Node* temp = parent->getRight();
	  parent->setRight(nullptr);
	  addRecur2(temp->getLeft());
	  addRecur2(temp->getRight());
	  delete temp;
	  return;
	}
      removeRecur(parent->getRight(), input);//right otherwise
    }
}

void BST::print1()
{
  print(head, 0);
}

void BST::print(Node* header, int space)
{
  if(header == nullptr)
    {//if the header is null, return
      return;
    }
  space += 4;//add the space by 4
  print(header->getRight(), space);//print out right side
  cout << endl;
  for(int i=4; i<space; i++)
    {//print out the spacing
      cout << " ";
    }
  cout << header->getValue() << endl;//print out the header's value
  print(header->getLeft(), space);//print out the left side
}

void BST::search(int input)
{
  searchRecur(head, input);
}

void BST::searchRecur(Node* parent, int input)
{
  if(parent == nullptr)
    {//if the tree does not conatin the number
      cout << "This number is not in the tree" << endl;
      return;
    }

  //check if parent value is equal to input
  if(parent->getValue() == input)
    {
      cout << "This number is in the tree" << endl;
      return;
    }

  //check smaller or bigger than parent
  if(input < parent->getValue())
    {
      searchRecur(parent->getLeft(), input);//check left side if smaller
    }
  else
    {
      searchRecur(parent->getRight(), input);//check right side if otherwise
    }
}
