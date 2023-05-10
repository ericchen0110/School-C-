/*Written by Eric Chen
  Date: 4/29/2023
  This is the main funciton of the red black tree proejct
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include "RBT.h"

using namespace std;

int main()
{
  RBT* myTree = new RBT();//make the tree

  while(true)
    {
      cout << "__________________________________________________________________" << endl;
      cout << "What do you want to do? Insert, Read, Delete, Print, Quit" << endl;

      //get input
      char input[100];
      cin.getline(input, 100);
      
      if(strcmp(input, "Read") == 0)
	{
	  //read
	  vector<int> *input_vector = new vector<int>;//make input vector

	  cout << "Do you want to from console or from a file? Type \"console\" for console and \"file\" for file" << endl;
	  char input1[100];
	  cin.getline(input1, 100);

	  if(strcmp(input1, "console") == 0)
	    {//console
	      cout << "Type your numbers here, type -1 at the end of the numbers" << endl;
	      int inputInt = 0;
	      cin >> inputInt;
	      while(inputInt != -1)
		{
		  input_vector->push_back(inputInt);
		  cin >> inputInt;
		}
	      cin.get();
	    }
	  else if(strcmp(input1, "file") == 0)
	    {//file
	      cout << "File name: ";
	      char name[100];
	      cin.getline(name, 100);
	      ifstream fInput(name);
	      int fileInput = 0;

	      while(!fInput.eof())
		{
		  fInput >> fileInput;
		  input_vector->push_back(fileInput);
		}
	    }

	  //input everything from vector to the tree
	  for(int i=0; i<input_vector->size(); i++)
	    {
	      myTree->insert((*input_vector)[i]);
	    }
	}
      else if(strcmp(input, "Insert") == 0)
	{
	  //insert
	  cout << "Number:";
	  int input2 = 0;
	  cin >> input2;
	  myTree->insert(input2);
	  cin.get();
	}
      else if(strcmp(input, "Delete") == 0)
	{
	  //delete
	  cout << "Number:";
	  int input3 = 0;
	  cin >> input3;
	  myTree->deleteFun(input3);
	  cin.get();
	}
      else if(strcmp(input, "Print") == 0)
	{
	  //print
	  myTree->print();
	}
      else if(strcmp(input, "Quit") == 0)
	{
	  break;
	}
    }

}
