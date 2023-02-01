#ifndef NODE_H
#define NODE_H
#include <iostream>
#include "student.h"

using namespace std;

class Node{
 public:
  Node(Student* myStudent);//constructor
  ~Node();//destructor
  virtual Node* getNext();//return a pointer to the next node
  virtual Student* getStudent();//returns a pointer to the student stored
  virtual void setNext(Node* myNode);//setting the next pointer

 private:
  Student* myStudent;
  Node* myNode;
};
#endif
