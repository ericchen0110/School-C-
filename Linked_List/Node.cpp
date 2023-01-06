#include <iostream>
#include <cstring>

#ifndef STUDENT_H
#define STUDENT_H
#include "student.h"
#endif

#ifndef NODE_H
#define NODE_H
#include "Node.h"
#endif

using namespace std;

Node::Node(Student* myStudent)
{
  this->myStudent = new Student(myStudent->get_first_name(), myStudent->get_last_name(), myStudent->get_id(), myStudent->get_gpa());
}

Node::~Node()
{
  
}

Node* Node::getNext()
{
  return myNode;
}

Student* Node::getStudent()
{
  return myStudent;
}

void Node::setNext(Node* myNode)
{
  this->myNode = myNode;
}
