#include <iostream>
#include <cstring>

#ifndef PARENT_H
#define PARENT_H
#include "Parent.h"
#endif

#ifndef MOVIE_H
#define MOVIE_H
#include "Movie.h"
#endif

movie::movie(char* title, int year, float rating, char* director, int duration):parent(title, year)
{
  this->rating = rating;
  strcpy(this->director, director);
  this->duration = duration;
  type = 2;
}

float movie::get_rating()
{
  return rating;
}

char* movie::get_director()
{
  return director;
}

int movie::get_duration()
{
  return duration;
}
