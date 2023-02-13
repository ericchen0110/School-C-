#include <iostream>
#include <cstring>
#include <math.h>
#include <bits/stdc++.h>
#include <fstream>
#include "student.h"
#include "node.h"

using namespace std;

int hashFun(int id, int slots);
int getDigit(int num, int length, int digit);
int ADD(Node** hash_table, int slots, Student* new_student);
int random_student(int count, Node** hash_table, int slots);
int newHash(int slots, Node** hash_table);
void printHash(Node** hash_table, int slots);
bool printRecur(Node* header, int id);
void deleteFun(Node** hash_table, int slots);
bool deleteRecur(Node** hash_table, int hash_value, Node* header, int id);

int main()
{
  Node** hash_table = new Node*[100];
  int slots = 100;
  for(int i=0; i<100; i++)
    {
      hash_table[i] = NULL;
      }
  while(true)
    {
      cout << "______________________________________________________" << endl;
      //get input
      char input[100];
      cout << "What do you want to do? (ADD, PRINT, DELETE or QUIT)\nIf you want to generate students, type GENERATE" << endl;
      cin >> input;

      if(strcmp(input, "ADD") == 0)
	{
	  //add
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

	  //make the student
	  Student* new_student = new Student(fName, lName, id, gpa);

	  slots = ADD(hash_table, slots, new_student);
	}
      else if(strcmp(input, "PRINT") == 0)
	{
	  //print
	  printHash(hash_table, slots);
	}
      else if(strcmp(input, "DELETE") == 0)
	{
	  //delete
	  deleteFun(hash_table, slots);
	}
      else if(strcmp(input, "GENERATE") == 0)
	{
	  //generate
	  int count = 0;
	  cout << "How many students would you like to generate and add?" << endl;
	  cin >> count;
	  slots = random_student(count, hash_table, slots);
	}
      else if(strcmp(input, "QUIT") == 0)
	{
	  //quit
	  break;
	}
    }
  
  return 0;
}

void deleteFun(Node** hash_table, int slots)
{
  cout << "ID of the student that you want to delete: ";
  int id;
  cin >> id;

  //get the hash value
  int hash_value = hashFun(id, slots);

  if(deleteRecur(hash_table, hash_value, hash_table[hash_value], id))
    {
      cout << "Student deleted" << endl;
    }
  else
    {
      cout << "Student not found." << endl;
    }
}

bool deleteRecur(Node** hash_table, int hash_value, Node* header, int id)
{
  //checkm if header is NULL
  if(header == NULL)
    {
      return false;
    }

  //check if the header contains the student
  if(header->getStudent()->get_id() == id)
    {
      cout << header->getStudent()->get_first_name() << " " << header->getStudent()->get_last_name() << ", " << header->getStudent()->get_gpa() << ", " << header->getStudent()->get_id() << endl;
      cout << "\nIs this the student you want to delete? (Yes or No)" << endl;
      char input[100];
      cin >> input;
      if(strcmp(input, "Yes") == 0)
	{
	  //if the only one in the list
	  if(header == hash_table[hash_value] && header->getNext() == NULL)
	    {
	      delete header;
	      hash_table[hash_value] = NULL;
	    }
	  //if the end of the list
	  else if(header->getNext() == NULL)
	    {
	      
	    }
	}
      else
	{
	  return false;
	}
    }
  else
    {
      deleteRecur(header->getNext(), id);
    }
  
  return false;
}

void printHash(Node** hash_table, int slots)
{
  //ask for the student's ID
  cout << "Student ID: ";
  int id;
  cin >> id;

  //get the hash vlaue
  int hash_value = hashFun(id, slots);
  
  //print
  cout << endl;
  if(!printRecur(hash_table[hash_value], id))
    {
      cout << "Student not found" << endl;
    }
}

bool printRecur(Node* header, int id)
{
  //check if header is null
  if(header == NULL)
    {
      return false;
    }

  //check if the header contains the student
  if(header->getStudent()->get_id() == id)
    {
      cout << header->getStudent()->get_first_name() << " " << header->getStudent()->get_last_name() << ", " << header->getStudent()->get_gpa() << ", " << header->getStudent()->get_id() << endl;
      return true;
    }
  else
    {
      printRecur(header->getNext(), id);
    }
  return false;
}

int random_student(int count, Node** hash_table, int slots)
{
  int new_slots = slots;
  cout << endl;
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
      new_slots = ADD(hash_table, slots, new_student);

      //print out the student added
      cout << "Student added: " << fName << " " << lName << ", " << gpa << ", " << id << endl;
    }

  return new_slots;
}

int hashFun(int id, int slots)
{
  //take the first, third, and fifth digit of the student's ID and make a three digit number. Then take the reminder of deviding the number by 100 as the hash  number

  int firstD = getDigit(id, 6, 1);
  int thirdD = getDigit(id, 6, 3);
  int fifthD = getDigit(id, 6, 5);
  
  int output = firstD*100 + thirdD*10 + fifthD;

  return output%slots;
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

int ADD(Node** hash_table, int slots, Student* new_student)
{
  //hash the id
  int hash_value = hashFun(new_student->get_id(), slots);
  
  //add to a node
  Node* new_node = new Node(new_student);

  //add to the hash_table array
  if(hash_table[hash_value] == NULL)
    {
      hash_table[hash_value] = new_node;
    }
  else if(hash_table[hash_value]->getNext() == NULL)
    {
      hash_table[hash_value]->setNext(new_node);
    }
  else if(hash_table[hash_value]->getNext()->getNext() == NULL)
    {
      hash_table[hash_value]->getNext()->setNext(new_node);
    }
  else
    {
      //more than three values in the linked list
      return newHash(2*slots, hash_table);
    }
  
  return slots;
}

int newHash(int slots, Node** hash_table)
{
  //make a new hash tablle
  Node** new_table = new Node*[slots];

  //copy old table into new table
  for(int i=0; i< (slots/2); i++)
    {
      new_table[i] = hash_table[i];
    }

  //relocate hash_table
  hash_table = new_table;

  return slots;
}
