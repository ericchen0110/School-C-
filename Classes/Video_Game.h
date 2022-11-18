#include <iostream>
#include "Parent.h"

class video_game : public parent
{
 public:
  video_game(char* title, int year, char* publisher, float rating);
  virtual char* get_publisher();
  virtual float get_rating();
private:
  char* publisher;
  float rating;
}
