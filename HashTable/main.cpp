#include <iostream>
#include <cstring>
#include <math.h>
#include "student.h"
#include "node.h"

using namespace std;

int hashFun(int id);
int getDigit(int num, int length, int digit);
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

  int firstD = getDigit(id, 6, 1);
  int thirdD = getDigit(id, 6, 3);
  int fifthD = getDigit(id, 6, 5);
  
  cout << "firstD: " << firstD << endl;
  cout << "thirdD: " << thirdD << endl;
  cout << "fifthD: " << fifthD << endl;
  
  int output = firstD*100 + thirdD*10 + fifthD;

  cout << "output1: " << output << endl;
  output = output%100;

  cout << "output2: " << output << endl;
  
  return 1;
}

int getDigit(int num, int length, int digit)
{
  //cout << "digit: " << digit << endl;
  //cout << "num inside" << num << endl;
  
  if(digit == 1)
    {
      //cout << "working1\n";
      //cout << "num orgin: " << num << endl;
      //cout << "num: " << num/pow(10, length) << endl;
      return num/pow(10, length-1);
    }
  else if(digit > 1 && length == digit)
    {
      int temp = num/pow(10, length-1);
      num -= temp;
      getDigit(num, length-1, digit-1);
    }
  else if(digit > 1 )
    {
      num = (num/pow(10, (length-digit)));
      getDigit(num, digit, digit);
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

  //cout << "value: " << hash_value << endl;
  //add to the hash_table array
  //hash_table[hash_value]->setNext(new_node);
}
