#include <iostream>
#include <cstring>
#include "node.h"
#include "student.h"

using namespace std;

void ADD(Node* head);
void PRINT(Node* head);
void DELETE(Node* head);
void AVERAGE(Node* head);
void LOOP(Node* head, Node* new_node);

int main()
{
  //make a header pointer
  Node *head = new Node();
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
	  PRINT(head);
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

void PRINT(Node* head)
{
  if(head->getNext() == NULL)
    {
      return;
    }
  else
    {
      cout << head->getNext()->getStudent()->get_first_name() << " " << head->getNext()->getStudent()->get_last_name() << ", " << head->getNext()->getStudent()->get_id() << ", " << head->getNext()->getStudent()->get_gpa() << endl;
      PRINT(head->getNext());
    }
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
  new_node->setNext(NULL);
  LOOP(head, new_node);

  return;
}

void LOOP(Node* head, Node* new_node)
{
  if(head->getNext() == NULL)
    {
      head->setNext(new_node);
      return;
    }
  else if(head->getNext()->getNext() == NULL)
    {
      if(head->getNext()->getStudent()->get_id() <= new_node->getStudent()->get_id())
	{
	  head->getNext()->setNext(new_node);
	  return;
	}
      else if(head->getNext()->getStudent()->get_id() > new_node->getStudent()->get_id())
	{
	  new_node->setNext(head->getNext());
	  head->setNext(new_node);
	  return;
	}
    }
  else if(head->getNext()->getStudent()->get_id() <= new_node->getStudent()->get_id() && head->getNext()->getNext()->getStudent()->get_id() >= new_node->getStudent()->get_id())
    {
      new_node->setNext(head->getNext());
      head->setNext(new_node);
      return;
    }
  else
    {
      LOOP(head->getNext(), new_node);
    }
    return;
}
