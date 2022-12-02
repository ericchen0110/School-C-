#include <iostream>

#ifndef PARENT_H
#define PARENT_H
#include "Parent.h"
#endif

#ifndef MUSIC_H
#define MUSIC_H
#include "Music.h"
#endif

music::music(char* title, int year, char* artist, char* publisher, int duration):parent(title, year)
{
  this->artist = artist;
  this->publisher = publisher;
  this->duration = duration;
}

char* music::get_artist()
{
  return artist;
}

char* music::get_publisher()
{
  return publisher;
}

int music::get_duration()
{
  return duration;
}

char* music::get_type()
{
  return "music";
}
