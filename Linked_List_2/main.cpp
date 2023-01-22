/*Date: 1/21/2023
  Written by Eric Chen
  This is the main function of Linked List. It creates a linked list to store students and allows the user to add, print, delete, or average the gpa.
*/

#include <iostream>
#include <cstring>
#include <cmath>
#include <bits/stdc++.h>
#include "node.h"
#include "student.h"

using namespace std;

//define all functions
void ADD(Node* head);
void PRINT(Node* head);
void DELETE(Node* head);
void AVERAGE(Node* head, float sum, int count);
void LOOP_ADD(Node* head, Node* new_node);
bool LOOP_DELETE(Node* head, int ID, bool deleted);

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
	  cout << endl;
	  PRINT(head);
	}
      else if(strcmp(input, "DELETE") == 0)
	{
	  //delete
	  DELETE(head);
	}
      else if(strcmp(input, "AVERAGE") == 0)
	{
	  //average
	  cout << endl;
	  AVERAGE(head, 0, 0);
	}
      else if(strcmp(input, "QUIT") == 0)
	{
	  //quit
	  break;
	}
    }
  return 0;
}

void AVERAGE(Node* head, float sum, int count)
{
  //check if reached the end
  if(head->getNext() == NULL)
    {
      float value = (sum / count);
      cout << "The average GPA is: " << fixed << setprecision(2) << value << endl;
      return;
    }
  //add gpa to the sum
  else
    {
      sum += head->getNext()->getStudent()->get_gpa();
      AVERAGE(head->getNext(), sum, count+=1);
    }
  
  return;
}

void DELETE(Node* head)
{
  //ask for the id
  int input;
  cout << "What is the student ID of the student that you want to delete?" << endl;
  cin >> input;

  //print out message
  if(LOOP_DELETE(head, input, false))
    {
      cout << "\nStudent Deleted" << endl;
    }
  else
    {
      cout << "\nStudent does not exist" << endl;
    }
  return;
}

void PRINT(Node* head)
{
  //check if reached the end
  if(head->getNext() == NULL)
    {
      return;
    }
  //print out each student
  else
    {
      cout << head->getNext()->getStudent()->get_first_name() << " " << head->getNext()->getStudent()->get_last_name() << ", " << head->getNext()->getStudent()->get_id() << ", " << fixed << setprecision(2) << head->getNext()->getStudent()->get_gpa() << endl;
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
  LOOP_ADD(head, new_node);

  return;
}

void LOOP_ADD(Node* head, Node* new_node)
{
  //check if reached the end
  if(head->getNext() == NULL)
    {
      head->setNext(new_node);
      return;
    }
  //check if the student id matches the input id
  else if(head->getNext()->getStudent()->get_id() >= new_node->getStudent()->get_id())
    {
      new_node->setNext(head->getNext());
      head->setNext(new_node);
      return;
    }
  else
    {
      LOOP_ADD(head->getNext(), new_node);
    }
    return;
}

bool LOOP_DELETE(Node* head, int ID, bool deleted)
{
  //check if the student exists
  if(head->getNext() == NULL)
    {
      //return false;
      deleted = false;
    }
  //check if the student id matches the input id
  else if(head->getNext()->getStudent()->get_id() == ID)
    {
      //double check if this is the student the user wants to delete
      char input[100];
      cout << endl << head->getNext()->getStudent()->get_first_name() << " " << head->getNext()->getStudent()->get_last_name() << ", " << head->getNext()->getStudent()->get_id() << ", " << head->getNext()->getStudent()->get_gpa() << endl;
      cout << "\nIs this the student that you want to delete? (yes or no)" << endl;
      cin >> input;
      if(strcmp(input, "yes") == 0)
	{
	  //if the student if at the end of the list
	  if(head->getNext()->getNext() == NULL)
	    {
	      delete head->getNext();
	      head->setNext(NULL);
	    }
	  //otherwise
	  else
	    {
	      Node *temp = new Node();
	      temp->setNext(head->getNext()->getNext());
	      delete head->getNext();
	      head->setNext(temp->getNext());
	      delete temp;
	    }
	  //return true;
	  deleted = true;
	  return deleted;
	}
      else
	{
	  //return false;
	  deleted = false;
	}
    }
  else
    {
      deleted = LOOP_DELETE(head->getNext(), ID, deleted);
    }
  return deleted;
}
