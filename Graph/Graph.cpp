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
  else
    {
      cout << "This vertex already exists" << endl;
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
  char *vertexArr = new char[vertexNum];
  int *distance = new int[vertexNum];
  char *previousV = new char[vertexNum];

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

  beginning(visited, unvisited, vertexArr, distance, previousV, position);

  //output the result
  int outputPosition = findVerDistanceNum(B, vertexArr);
  int outputNum = 0;
  //outputNum = outputFun(A, vertexArr, distance, previousV, outputPosition, 0);


  
  cout << "The shortest path is " << outputNum << endl;

  cout << vertexArr[0] << " Distance: " << distance[0] << endl;
  cout << vertexArr[0] << " Previous: " << previousV[0] << endl;
  cout << vertexArr[1] << " Distance: " << distance[1] << endl;
  cout << vertexArr[1] << " Previous: " << previousV[1] << endl;
  cout << vertexArr[2] << " Distance: " << distance[2] << endl;
  cout << vertexArr[2] << " Previous: " << previousV[2] << endl;
  
}

int Graph::outputFun(char A, char vertexArr[], int distance[], char previousV[], int outputPosition, int outputNum)
{
  //cout << "Output Position" << outputPosition << endl;
  
  if(previousV[outputPosition] == A)
    {
      outputNum += distance[outputPosition];
      return outputNum;
    }

  outputNum += distance[outputPosition];
  
  //change outputPosition
  int temp = 0;
  temp = findVerDistanceNum(previousV[outputPosition], vertexArr);
  outputPosition = temp;
  
  return outputFun(A, vertexArr, distance, previousV, outputPosition, outputNum);
}

void Graph::beginning(vector<char> *visited, vector<char> *unvisited, char vertexArr[], int distance[], char previousV[], int position)
{
  //check if the unvisited is zero
  if(visited->size() == charVec->size())
    {
      return;
    }

  //visit unvisited vertex with shortest distance from the start
  char current = smallestUnvisited(vertexArr, distance, charVec->size(), visited);
  
  //calculate the distance from current to unvisited neighbours
  int nextLocation = -1;
  for(int i=0; i < charVec->size(); i++)
    {
      nextLocation = findVerLocation(vertexArr[i]);

      if((*numTable)[position][nextLocation] > 0 && unvisitedFun(vertexArr[i], unvisited))
	 {	  
	  int thisDistance = (*numTable)[position][nextLocation];
	  calculateDistance(position, i, thisDistance, vertexArr, distance, previousV);
	}
    }

  //update visited and unvisited arrays
  visited->push_back(vertexArr[position]);

  for(int i=0; i < unvisited->size(); i++)
    {
      if((*unvisited)[i] == vertexArr[position])
	{
	  unvisited->erase(unvisited->begin() + i);
	}
    }
  
  //recursion
  position += 1;
  beginning(visited, unvisited, vertexArr, distance, previousV, position);
}

void Graph::calculateDistance(int currentLocation, int nextLocation, int thisDistance, char vertexArr[], int distance[], char previousV[])
{  
  int currentDistance = -1;

  if(previousV[currentLocation] == '\0')
    {
      currentDistance = 0;
    }
  else
    {
      int lastLocation = findVerDistanceNum(previousV[currentLocation], vertexArr);
      currentDistance = distance[lastLocation];
    }

  //add the distance
  currentDistance += thisDistance;

  //compare to current distance

  cout << "Current distance: " << currentDistance << endl;
  cout << "Distance in the table: " << distance[nextLocation] << endl;
  
  if(currentDistance < distance[nextLocation])
    {
      distance[nextLocation] = currentDistance;
      previousV[nextLocation] = vertexArr[currentLocation];
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
	  return true;
	}
    }

  return false;
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
