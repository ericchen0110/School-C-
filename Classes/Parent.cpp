#include <iostream>
#include "parent.h"

parent::parent(char* title, int year)
{
  this.title = title;
  this.year = year;
  cout << "parent constructor" << endl;
}

virtual char* parent::get_title()
{
  return title;
}

virtual int parent::get_year()
{
  return year;
}
