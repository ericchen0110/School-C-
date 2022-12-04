#include <iostream>

#ifndef PARENT_H
#define PARENT_H
#include "Parent.h"
#endif

class music : public parent
{
 public:
  music(char* title, int year, char* artist, char* publisher, int duration);
  ~music();
  virtual char* get_artist();
  virtual char* get_publisher();
  virtual int get_duration();
 private:
  char* artist = new char[81];
  char* publisher = new char[81];
  int duration;
};
