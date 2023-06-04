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
  //check if the vertices exist
  bool existA = false;
  bool existB = false;
  int starting = 0;
  
  for(int i=0; i < charVec->size(); i++)
    {
      if((*charVec)[i] == A)
	{
	  starting = i;
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

  //find the path
  int vertexNum = charVec->size();
  
  //make the output array
  char vertexArr[vertexNum];
  int distance[vertexNum];
  char previousV[vertexNum];

  //initialize arrays
  for(int i=starting; i < charVec->size(); i++)
    {
      vertexArr[i-starting] = (*charVec)[i];
    }

  for(int i=0; i < starting; i++)
    {
      vertexArr[i+starting+1] = (*charVec)[i];
    }

  distance[0] = 0;
  previousV[0] = '\0';
  for(int i=1; i < vertexNum; i++)
    {
      distance[i] = 10000;
      previousV[i] = '\0';
    }

  //make visited and unvisited vectors
  vector<char> *visited = new vector<char>();
  vector<char> *unvisited = new vector<char>();

  for(int i=0; i < vertexNum; i++)
    {
      unvisited->push_back((*charVec)[i]); 
    }

  //visit unvisted vertex with shortest distance from the start
  int position = 0;
  while(unvisited->size() != 0)
    {
      char current = smallestUnvisited(vertexArr, distance, vertexNum, visited);

      int currentLocation = -1;
      for(int i=0; i < vertexNum; i++)
	{
	  if((*charVec)[i] == current)
	    {
	      currentLocation = i;
	      break;
	    }
	}

      //calculate the distance from current to unvisited neighbours
      int currentD = 0;
      for(int i=0; i < vertexNum; i++)
	{
	  if((*numTable)[currentLocation][i] > 0 && unvisitedFun(current, unvisited))
	    {
	      currentD = distance[position] + (*numTable)[currentLocation][i];
	      
	      if(currentD < distance[findVerDistanceNum((*charVec)[i], vertexArr)])
		{
		  distance[findVerDistanceNum((*charVec)[i], vertexArr)] = currentD;
		  previousV[findVerDistanceNum((*charVec)[i], vertexArr)] = (*charVec)[position];
		}
	    }
	}

      visited->push_back(vertexArr[position]);

      int thisPosition = 0;
      for(int i=0; i < unvisited->size(); i++)
	{
	  if((*unvisited)[i] == vertexArr[position])
	    {
	      thisPosition = i;
	    }
	}
      unvisited->erase(unvisited->begin() + thisPosition);
    }
}

int Graph::findVerDistanceNum(char input, char vertexArr[])
{
  int location = -1;
  for(int i=0; i < charVec->size(); i++)
    {
      if(vertexArr[i] == input)
	{
	  location = i;
	}
    }

  return location;
}

int Graph::findVerLocation(char input)
{
  for(int i=0; i < charVec->size(); i++)
    {
      if((*charVec)[i] == input)
	{
	  return i;
	}
    }

  return -1;
}

bool Graph::unvisitedFun(char input, vector<char> *unvisited)
{
  for(int i=0; i < unvisited->size(); i++)
    {
      if(input == (*unvisited)[i])
	{
	  return false;
	}
    }

  return true;
}

char Graph::smallestUnvisited(char vertexArr[], int distance[], int vertexNum, vector<char> *visited)
{
  int smallest = 100000;
  int position = -1;
  char returnValue = '\0';

  for(int i=0; i < vertexNum; i++)
    {
      if(distance[i] < smallest)
	{
	  smallest = distance[i];
	  position = i;
	  returnValue = vertexArr[i];
	}
    }

  for(int i=0; i < visited->size(); i++)
    {
      if((*visited)[i] == returnValue)
	{
	  returnValue = '\0';
	  break;
	}
    }
    
  return returnValue;
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
