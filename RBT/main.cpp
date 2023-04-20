#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include "RBT.h"

using namespace std;

int main()
{
  vector<int> *input_vector = new vector<int>;//create the input vector

  //ask if the user wants to input from console or file
  cout << "Do you want to input from console or file? Type \"console\" for console and \"file\" for file." << endl;
  char input1[100];
  cin.get(input1, 100);
  cin.get();
  if(strcmp(input1, "console") == 0)
    {//input from console
      cout << "Type your numbers here, type -1 at the end of the numbers" << endl;
      int input_int = 0;
      cin >> input_int;
      while(input_int != -1)
	{
	  input_vector->push_back(input_int);
	  cin >> input_int;
	}
    }
  else if(strcmp(input1, "file") == 0)
    {//input from file
      cout << "File name: ";
      char name[100];
      cin >> name;
      ifstream fInput(name);
      int fileInput = 0;
      
      while(!fInput.eof())
	{
	  fInput >> fileInput;
	  input_vector->push_back(fileInput);
	}
    }

  //put the numbers into a black red tree
  RBT* myTree = new RBT();//make a RBT
}
