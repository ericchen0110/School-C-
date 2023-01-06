#include <iostream>

#ifndef STUDENT_H
#define STUDENT_H
#include "Student.h"
#endif

using namespace std;

class Node{
 public:
  Node(Student* myStudent);
  ~Node();
  virtual Node* getNext();
  virtual Student* getStudent();
  virtual void setNext(Node* myNode);

 private:
  Student* myStudent;
  Node* myNode;
};
