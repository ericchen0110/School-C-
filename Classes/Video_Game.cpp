#include <iostream>
#ifndef PARENT_H
#define PARENT_H

#include "Parent.h"

#endif
#ifndef VIDEO_GAME_H
#define VIDEO_GAME_H

#include "Video_Game.h"

#endif

video_game::video_game(char* title, int year, char* publisher, float rating):parent(title, year)
{
  this->publisher = publisher;
  this->rating = rating;
  cout << "Video game constructor" << endl;
}

char* video_game::get_publisher()
{
  return publisher;
}

float video_game::get_rating()
{
  return rating;
}
