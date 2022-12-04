#include <iostream>
#include <cstring>
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
  strcpy(this->publisher, publisher);
  this->rating = rating;
  type = 1;
}

video_game::~video_game()
{
  delete[] title;
  delete[] publisher;
}

char* video_game::get_publisher()
{
  return publisher;
}

float video_game::get_rating()
{
  return rating;
}
