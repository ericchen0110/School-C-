#include <iostream>

#ifndef PARENT_H
#define PARENT_H
#include "Parent.h"
#endif

class movie : public parent
{
 public:
  movie(char* title, int year, float rating, char* director, int duration);
  virtual float get_rating();
  virtual char* get_director();
  virtual int get_duration();
  
 private:
  float rating;
  char* director = new char[81];
  int duration;
};
