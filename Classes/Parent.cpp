#include <iostream>
#ifndef PARENT_H
#define PARENT_H

#include "parent.h"

#endif

parent::parent(char* title, int year)
{
  this->title = title;
  this->year = year;
  cout << "parent constructor" << endl;
}

char* parent::get_title()
{
  return title;
}

int parent::get_year()
{
  return year;
}
