#include <iostream>
#include <cstring>
#ifndef PARENT_H
#define PARENT_H

#include "parent.h"

#endif

parent::parent(char* title, int year)
{
  strcpy(this->title, title);
  this->year = year;
}

char* parent::get_title()
{
  return title;
}

int parent::get_year()
{
  return year;
}

int parent::get_type()
{
  return type;
}
