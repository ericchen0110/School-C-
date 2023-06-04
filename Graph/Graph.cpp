#include "Graph.h"

using namespace std;

Graph::Graph()
{
  numTable = new vector<vector<int>>();
  charVec = new vector<char>();
}

void Graph::addVertex(char input)
{
  bool exist = false;
  for(int i=0; i<charVec->size(); i++)
    {
      if((*charVec)[i] == input)
	{
	  exist = true;
	  break;
	}
    }

  if(!exist)
    {
      charVec->push_back(input);
      if(charVec->size() == 1)
	{
	  numTable->push_back({0});
	}
      else
	{
	  vector<int> *temp = new vector<int>();
	  for(int i=0; i < charVec->size()-1; i++)
	    {
	      (*numTable)[i].push_back(-1);
	      temp->push_back(-1);
	    }
	  temp->push_back(0);
	  numTable->push_back(*temp);
	}
    }
}

void Graph::addEdge(char A, char B, int weight)
{
  //check if both A and B exist
  bool existA = false;
  bool existB = false;

  for(int i=0; i < charVec->size(); i++)
    {
      if((*charVec)[i] == A)
	{
	  existA = true;
	}

      if((*charVec)[i] == B)
	{
	  existB = true;
	}
    }

  if(!existA || !existB)
    {
      cout << "One of the vertices do not exist" << endl;
      return;
    }

  //add the edge
  int horiLocation = -1;
  int vertLocation = -1;
  
  for(int i=0; i < charVec->size(); i++)
    {
      if((*charVec)[i] == A)
	{
	  horiLocation = i;
	}

      if((*charVec)[i] == B)
	{
	  vertLocation = i;
	}
    }

  if((*numTable)[horiLocation][vertLocation] == -1)
    {
      (*numTable)[horiLocation][vertLocation] = weight;
      (*numTable)[vertLocation][horiLocation] = weight;
    }
  else
    {
      cout << "An edge already exists between these two vertices" << endl;
    }
}

void Graph::removeVertex(char input)
{
  //check if the vertex exists
  bool exist = false;
  int location = -1;
  for(int i=0; i < charVec->size(); i++)
    {
      if((*charVec)[i] == input)
	{
	  location = i;
	  exist = true;
	}
    }

  if(!exist)
    {
      cout << "This vertex does not exist" << endl;
      return;
    }

  //remove vertex
  charVec->erase(charVec->begin() + location);

  for(int i=0; i < numTable->size(); i++)
    {
      (*numTable)[i].erase((*numTable)[i].begin() + location);
    }
  numTable->erase(numTable->begin() + location);
}

void Graph::removeEdge(char A, char B)
{
  //check if vertices exist
  bool existA = false;
  bool existB = false;
  bool existE = false;

  int locationA = -1;
  int locationB = -1;
  
  for(int i=0; i < charVec->size(); i++)
    {
      if((*charVec)[i] == A)
	{
	  locationA = i;
	  existA = true;
	}
      if((*charVec)[i] == B)
	{
	  locationB = i;
	  existB = true;
	}
    }

  if(!existA || !existB)
    {
      cout << "One of the vertices do not exist" << endl;
      return;
    }

  //check if the edge exists
  if((*numTable)[locationA][locationB] == -1)
    {
      cout << "There is no edge between these two vertices" << endl;
      return;
    }

  //remove edge
  (*numTable)[locationA][locationB] = -1;
  (*numTable)[locationB][locationA] = -1; 
}

void Graph::shortPath(char A, char B)
{
  cout << "Point A: " << A << endl;
  cout << "Point B: " << B << endl;
}

void Graph::printFun()
{
  cout << " ";

  for(int i=0; i<charVec->size(); i++)
    {
      cout << "  ";
      cout << (*charVec)[i];
    }
  cout << endl;

  for(int i=0; i<charVec->size(); i++)
    {
      cout << (*charVec)[i];

      for(int j=0; j < numTable->size(); j++)
	{
	      cout << "  ";
	      cout << (*numTable)[i][j];
	    
	}
      cout << endl;
    }
}
