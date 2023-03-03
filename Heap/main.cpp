#include <iostream>
#include <cstring>
#include <fstream>
#include "heap.h"

using namespace std;

int main()
{
  //get input
  cout << "Do you want to input numbers through the console or a file? For console, type \"console\", for file, type \"file\"." << endl;
  char input[100];
  cin >> input;
  int number[100];
  for(int i=0; i<100; i++)
    {
      number[i] = 0;
    }
  
  if(strcmp(input, "console") == 0)
    {
      //console
      int count;
      while(true)
	{
	  cout << "How many numbers do  you want to enter?" << endl;
	  cin >> count;
	  if(count > 100)
	    {
	      cout << "That's too many numbers. Either use the file input or put a smaller number." << endl;
	    }
	  else
	    {
	      break;
	    }
	}
      cout << "Enter your numbers: ";
      for(int i=0; i<count; i++)
	{
	  cin >> number[i];
	}
    }
  else if(strcmp(input, "file") == 0)
    {
      //file
      cout << "File name: ";
      char name[100];
      cin >> name;

      ifstream fNum (name);
      
      for(int i=0; i<100; i++)
	{
	  if(fNum.eof())
	    {
	      break;
	    }
	  fNum >> number[i];
	}
    }

  //make a heap
  heap *my_heap = new heap();

  /*my_heap->addNum(number[0]);
  cout << my_heap->remove() << endl;
  */

  //add the numbers into a heap
  for(int i=0; i<100; i++)
    {
      my_heap->addNum(number[i]);
     }
  
  //actions
  cout << "What do you want to do? \"REMOVE\" to output the largest value, \"ALL\" to remove and output everything from the heap, \"DISPLAY\" to see the entire heap in a visual way." << endl;
  char input2[100];
  cin >> input2;

    if(strcmp(input2, "REMOVE") == 0)
      {
	//remove biggest value
	int output = my_heap->remove();
	cout << "The output is " << output << endl;
      }
    else if(strcmp(input2, "ALL") == 0)
      {
	//remove everthing
	for(int i=0; i<100; i++)
	  {
	    cout << my_heap->remove() << " ";
	  }
      }
    else if(strcmp(input2, "DISPLAY") == 0)
      {
	//display everthing
      }
    else if(strcmp(input2, "TEST") == 0)
      {
	for(int i=0; i<101; i++)
	  {
	    cout << (my_heap->getArr())[i] << " ";
	  }
      }
    else
      {
	cout << "That is not a command" << endl;
      }

  return 0;
}
