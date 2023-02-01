#include <iostream>
#include <cstring>
#include <math.h>
#include <bits/stdc++.h>
#include <fstream>
#include "student.h"
#include "node.h"

using namespace std;

int hashFun(int id);
int getDigit(int num, int length, int digit);
void ADD(Node** hash_table);
void random_student(int count);

int main()
{
  Node** hash_table = new Node*[100];
  while(true)
    {
      //get input
      char input[100];
      cout << "What do you want to do? (ADD, PRINT, DELETE or QUIT)\nIf you want to generate students, type GENERATE" << endl;
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
      else if(strcmp(input, "GENERATE") == 0)
	{
	  //generate
	  int count = 0;
	  cout << "How many students would you like to generate and add?" << endl;
	  cin >> count;
	  random_student(count);
	}
      else if(strcmp(input, "QUIT") == 0)
	{
	  //quit
	  break;
	}
    }
  
  return 0;
}

void random_student(int count)
{
  for(int i=0; i<count; i++)
    {
      //grab first name
      ifstream firstName ("firstName.txt");
      char fName[100];
      char temp[100];
      for(int j=0; j<(rand()%20); j++)
	{
	  firstName >> temp;
	}
      firstName >> fName;
      
      //grab last name
      ifstream lastName("lastName.txt");
      char lName[100];
      for(int j=0; j<(rand()%20); j++)
	{
	  lastName >> temp;
	}
      lastName >> lName;

      //generate id
      int id = 100000 + i;

      //generate gpa
      int first = rand()%3;
      int second = rand()%10;
      int third = rand()%10;

      float gpa = (float)(first) + (float)(second/10.00) + (float)(third/100.00);

      //make student
      Student* new_student = new Student(fName, lName, id, gpa);

      //add to the hash table
      
    }
}

int hashFun(int id)
{
  //take the first, third, and fifth digit of the student's ID and make a three digit number. Then take the reminder of deviding the number by 100 as the hash  number

  int firstD = getDigit(id, 6, 1);
  int thirdD = getDigit(id, 6, 3);
  int fifthD = getDigit(id, 6, 5);
  
  int output = firstD*100 + thirdD*10 + fifthD;

  return output%100;
}

int getDigit(int num, int length, int digit)
{
  if(digit == 1)
    {
      return num/pow(10, length-1);
    }
  else if(digit > 1 && length == digit)
    {
      int temp = num/pow(10, length-1);
      num -= (temp*pow(10, length-1));
      return getDigit(num, length-1, digit-1);
    }
  else if(digit > 1 )
    {
      num = (num/pow(10, (length-digit)));
      return getDigit(num, digit, digit);
    }
  
  return -1;
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

  cout << "value: " << hash_value << endl;
  //add to the hash_table array
  hash_table[hash_value]->setNext(NULL);
}
