#include <iostream>
#include <cstring>

#ifndef STUDENT_H
#define STUDENT_H
#include "Student.h"
#endif

using namespace std;

Student::Student(char* first_name, char* last_name, int id, float gpa)
{
  strcpy(this->first_name, first_name);
  strcpy(this->last_name, last_name);
  this->id = id;
  this->gpa = gpa;
}

Student::~Student()
{
  delete[] first_name;
  delete[] last_name;
}

char* Student::get_first_name()
{
  return first_name;
}

char* Student::get_last_name()
{
  return last_name;
}

int Student::get_id()
{
  return id;
}

float Student::get_gpa()
{
  return gpa;
}

