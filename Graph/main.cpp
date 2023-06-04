#include <iostream>
#include "Graph.h"
#include <cstring>
#include <cctype>

using namespace std;

int main()
{
  //make the graph
  Graph *newGraph = new Graph();
  
  while(true)
    {
      //ask user for action
      cout << "_____________________________________________________" << endl;
      cout << "What do you want to do?" << endl;
      cout << "\"addV\" to add a vertex" << endl << "\"addE\" to add an edge" << endl;
      cout << "\"removeV\" to remove a vertex" << endl << "\"removeE\" to remove an edge" << endl;
      cout << "\"shortPath\" to find the shortest path bewteen two vertices" << endl;
      cout << "\"Quit\" to quit" << endl << endl;

      char input[100];
      cin >> input;

      if(strcmp(input, "addV") == 0)
	{
	  //add vertex
	  cout << "____________________________________________________" << endl;
	  char label;
	  
	  do
	    {
	      cout << "Input your label (One Letter): ";
	      cin >> label;
	    }while(!isalpha(label));
	  
	  newGraph->addVertex(toupper(label));
	}
      else if(strcmp(input, "addE") == 0)
	{
	  //add edge
	  //make variables
	  char pointA;
	  char pointB;
	  int weight;

	  //ask for input
	  cout << "____________________________________________________" << endl;

	  do
	    {
	      cout << "Point A (One Letter): ";
	      cin >> pointA;
	    }while(!isalpha(pointA));

	  do
	    {
	      cout << "Point B (One Letter): ";
	      cin >> pointB;
	    }while(!isalpha(pointB));
	  
	  cout << "Edge Weight (A Number): ";
	  cin >> weight;

	  //call function
	  newGraph->addEdge(toupper(pointA), toupper(pointB), weight);
	}
      else if(strcmp(input, "removeV") == 0)
	{
	  //remove vertex
	  //make varaibles
	  char pointA;

	  //ask for input
	  cout << "____________________________________________________" << endl;

	  do
	    {
	      cout << "Point A (One Letter): ";
	      cin >> pointA;
	    }while(!isalpha(pointA));
	      
	  //call function
	  newGraph->removeVertex(toupper(pointA));
	}
      else if(strcmp(input, "removeE") == 0)
	{
	  //remove edge
	  //make varaibles
	  char pointA;
	  char pointB;

	  //ask for input
	  cout << "_____________________________________________________" << endl;

	  do
	    {
	      cout << "Point A (One Letter): ";
	      cin >> pointA;
	    }while(!isalpha(pointA));

	  do
	    {
	      cout << "Point B (One Letter): ";
	      cin >> pointB;
	    }while(!isalpha(pointB));

	  //call function
	  newGraph->removeEdge(toupper(pointA), toupper(pointB));
	}
      else if(strcmp(input, "shortPath") == 0)
	{
	  //short path
	  //make variables
	  char pointA;
	  char pointB;

	  //ask for input
	  cout << "__________________________________________________" << endl;

	  do
	    {
	      cout << "Point A (One Letter): ";
	      cin >> pointA;
	    }while(!isalpha(pointA));

	  do
	    {
	      cout << "Point B (One Letter): ";
	      cin >> pointB;
	    }while(!isalpha(pointB));

	  //call function
	  newGraph->shortPath(toupper(pointA), toupper(pointB));
	}
      else if(strcmp(input, "Print") == 0)
	{
	  newGraph->printFun();
	}
      else if(strcmp(input, "Quit") == 0)
	{
	  break;
	}
    }
  
  return 0;
}
