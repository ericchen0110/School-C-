/*Written by Eric Chen
  Date: 4/9/2023
  This is the main of a binary search tree program
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include "Node.h"
#include "BST.h"

using namespace std;

int main()
{
  vector<int> *input_vector = new vector<int>;//create the input vector
  
  //ask if want to input from console or file
  cout << "Do you want to input from console or file? type \"console\" for console and \"file\" for file" << endl;
  char input1[100];
  cin.get(input1, 100);
  cin.get();
  if(strcmp(input1, "console") == 0)
    {
      //read in from conosle
      cout << "\nType your numbers here, type -1 at the end of the numbers" << endl;
      int input_int = 0;
      cin >> input_int;
      while(input_int != -1)
	{
	  input_vector->push_back(input_int);
	  cin >> input_int;
	}
    }
  else if(strcmp(input1, "file") == 0)
    {
      //file
      cout << "File name: ";
      char name[100];
      cin >> name;
      ifstream fInput (name);
      int fileInput = 0;
      
      while(!fInput.eof())
	{
	  fInput >> fileInput;
	  input_vector->push_back(fileInput);
	}
    }
  else
    {
      cout << "That is not a command" << endl;
      return 0;
    }

  //go thru the vector and add them to the Binary Search Tree
  Node* head = new Node((*input_vector)[0]);//make the node for the head
  BST* new_BST = new BST(head);//make a BST
  
  for(int i=1; i<input_vector->size(); i++)//go thru the vector
    {
      new_BST->add((*input_vector)[i]);//add each number into the BST
    }

  //ask the user what they wanna do
  while(true)
    {
      cout << "__________________________________________________________\n";
      cout << "What do you want to do? (Add, Search, Print, Delete, Quit)" << endl;
      char input2[100];
      cin >> input2;

      if(strcmp(input2, "Search") == 0)
	{//search
	  cout << "Number: ";
	  int input3;
	  cin>>input3;
	  new_BST->search(input3);
	}
      else if(strcmp(input2, "Print") == 0)
	{//print
	  new_BST->print1();
	}
      else if(strcmp(input2, "Add") == 0)
	{//add
	  cout << "Number that you want to add: ";
	  int input3;
	  cin >> input3;
	  new_BST->add(input3);
	}
      else if(strcmp(input2, "Delete") == 0)
	{//delete
	  cout << "Number that you want to delete: ";
	  int input3;
	  cin >> input3;
	  new_BST->remove(input3);
	}
      else if(strcmp(input2, "Quit") == 0)
	{
	  break;
	}
    }
  
  return 0;
}
