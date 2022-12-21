#include <iostream>
#include <cstring>

#ifndef KEY_H
#define KEY_H
#include "key.h"
#endif

using namespace std;

key::key()
{
  
}

key::~key()
{
  delete[] name;
}

char* key::get_name()
{
  return name;
}

int key::get_number()
{
  return number;
}

void key::set_number(int setting)
{
  number = setting;
}
