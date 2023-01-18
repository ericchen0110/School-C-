#include <iostream>
#include <cstring>
#include "node.h"
#include "student.h"

using namespace std;

void ADD(Node* head);
void PRINT(Node* head);
void DELETE(Node* head);
void AVERAGE(Node* head);
Node* LOOP(Node* head);

int main()
{
  //make a header pointer
  Node *head;
  while(true)
    {
      cout << "___________________________________________________________________" << endl;
      cout << "Type ADD, PRINT, DELETE, or AVERAGE. Type QUIT if you want to quit." << endl;
      //get input
      char input[100];
      cin >> input;

      if(strcmp(input, "ADD") == 0)
	{
	  //add
	  ADD(head);
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

void ADD(Node* head)
{
  //input
  char first_name[100];
  char last_name[100];
  int id;
  float gpa;

  cout << "First name: ";
  cin >> first_name;
  cout << "Last name: ";
  cin >> last_name;
  cout << "ID: ";
  cin >> id;
  cout << "GPA: ";
  cin >> gpa;

  //make a new student
  Student *new_student = new Student(first_name, last_name, id, gpa);

  //make a new node
  Node *new_node = new Node(new_student);
  Node *final;
  final = LOOP(head);
  //final->setNext(new_node);
}

Node* LOOP(Node* head)
{
  if(head->getNext() == NULL)
    {
      return head;
    }
  else
    {
      LOOP(head->getNext());
    }
  return NULL;
}
