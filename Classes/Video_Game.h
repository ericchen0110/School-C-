#include <iostream>

#ifndef PARENT_H
#define PARENT_H

#include "Parent.h"

#endif

class video_game : public parent
{
 public:
  video_game(char* title, int year, char* publisher, float rating);
  virtual char* get_publisher();
  virtual float get_rating();
private:
  char* publisher;
  float rating;
};
