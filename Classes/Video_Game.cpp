#include <iostream>
#include "parent.h"
#include "Video_Game.h"

video_game::video_game(char* title, int year, char* publisher, float rating):parent(title, year)
{
  this->publisher = publisher;
  this->rating = rating;
  cout << "Video game constructor" << endl;
}
