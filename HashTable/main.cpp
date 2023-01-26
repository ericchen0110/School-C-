#include <iostream>
#include <cstring>
#include "student.h"
#include "node.h"

using namespace std;

int hashFun(int id);
void ADD(Node** hash_table);

int main()
{
  Node** hash_table = new Node*[100];
  while(true)
    {
      //get input
      char input[100];
      cout << "What do you want to do? (ADD, PRINT, DELETE or QUIT)" << endl;
      cin >> input;

      if(strcmp(input, "ADD") == 0)
	{
	  //add
	  ADD(hash_table);
	}
      else if(strcmp(input, "PRINT") == 0)
	{
	  //print
	}
      else if(strcmp(input, "DELETE") == 0)
	{
	  //delete
	}
      else if(strcmp(input, "QUIT") == 0)
	{
	  //quit
	  break;
	}
    }
  
  return 0;
}

int hashFun(int id)
{
  //take the first, third, and fifth digit of the student's ID and make a three digit number. Then take the reminder of deviding the number by 100 as the hash  number
  
  int firstD = id/100000;
  int thirdD = id/1000;
  int fifthD = id/10;
  
  int output = firstD*100 + thirdD*10 + fifthD;
  output = output%100;
  
  return output;
}

void ADD(Node** hash_table)
{
  //get input
  char fName[100];
  char lName[100];
  int id;
  float gpa;

  cout << "First Name: ";
  cin >> fName;
  cout << "Last Name: ";
  cin >> lName;
  cout << "ID: ";
  cin >> id;
  cout << "GPA: ";
  cin >> gpa;

  //hash the id
  int hash_value = hashFun(id);

  //make the student
  Student* new_student = new Student(fName, lName, id, gpa);

  //add to a node
  Node* new_node = new Node(new_student);

  //add to the hash_table array
  hash_table[hash_value]->setNext(new_node);
}
