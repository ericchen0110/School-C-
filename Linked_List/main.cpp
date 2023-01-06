//written by Eric Chen
//Date: 1/6/2023
//This main file tests the functions of the Node class and the Student class

#include <iostream>
#include <cstring>

#ifndef STUDENT_H
#define STUDENT_H
#include "Student.h"
#endif

#ifndef NODE_H
#define NODE_H
#include "Node.h"
#endif

using namespace std;

int main()
{
  //make a student
  char first[100];
  strcpy(first, "Eric");
  char last[100];
  strcpy(last, "Chen");

  char first1[100];
  strcpy(first1, "Nividh");
  char last1[100];
  strcpy(last1, "Singh");
  
  Student *myStudent = new Student(first, last, 492817, 4.2);
  Student *myStudent1 = new Student(first1, last1, 400300, 2.1);
  
  //make node
  Node *newNode = new Node(myStudent);
  Node *newNode1 = new Node(myStudent1);

  //test getStudent
  cout << newNode->getStudent()->get_first_name() << " " << newNode->getStudent()->get_last_name() << endl;
  cout << "ID: " << newNode->getStudent()->get_id() << endl;
  cout << "GPA: " << newNode->getStudent()->get_gpa() << endl;

  //test setNext and getNext
  newNode->setNext(newNode1);
  cout << newNode->getNext()->getStudent()->get_first_name() << endl;

  //delete
  delete myStudent;
  delete myStudent1;
  delete newNode;
  delete newNode1;
}
