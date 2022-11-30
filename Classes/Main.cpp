#include <iostream>
#include <cstring>
#include <vector>

#ifndef PARENT_H
#define PARENT_H
#include "parent.h"
#endif

#ifndef VIDEO_GAME_H
#define VIDEO_GAME_H
#include "Video_Game.h"
#endif

#ifndef MUSIC_H
#define MUSIC_H
#include "Music.h"
#endif

#ifndef MOVIE_H
#define MOVIE_H
#include "Movie.h"
#endif

using namespace std;

//define functions
void add(vector<parent*> *media_vector);

int main()
{
  //input
  char input[81];
  cout << "What do you want to do? (ADD, SEARCH, DELETE, QUIT)" << endl;
  cin >> input;

  //create vector
  vector<parent*> *media_vector = new vector<parent*>();

  //check input
  if(strcmp(input, "ADD") == 0)
    {
      //ADD
      add(media_vector);
    }
  else if(strcmp(input, "SEARCH") == 0)
    {
      //SEARCH
    }
  else if(strcmp(input, "DELETE") == 0)
    {
      //DELETE
    }
  else if(strcmp(input, "QUIT") == 0)
    {
      //QUIT
    }
}

void add(vector<parent*> *media_vector)
{
  //media type
  char type[81];
  cout << "What type of media do you want to add? (movie, music, video_game)" << endl;
  cin >> type;

  //ask for input to each field
  //title
  cout << "What is the title?" << endl;
  char title[81];
  cin >> title;

  //year
  cout << "What is the year?" << endl;
  int year;
  cin >> year;
  
  if(strcmp(type, "movie") == 0)
    {
      //movie
      //director
      cout << "What is the name of the director?" << endl;
      char director[81];
      cin >> director;

      //duration
      cout << "How long is the movie in minutes?" << endl;
      int duration;
      cin >> duration;

      //rating
      cout << "What is the rating?" << endl;
      float rating;
      cin >> rating;
    }
  else if(strcmp(type, "video_game") == 0)
    {
      //video game
      //publisher
      cout << "What is the name of the publisher?" << endl;
      char publisher[81];
      cin >> publisher;

      //rating
      cout << "What is the rating?" << endl;
      float rating;
      cin >> rating;
    }
  else if(strcmp(type, "music") == 0)
    {
      //music
      //artist
      cout << "What is the name of the artist?" << endl;
      char artist[81];
      cin >> artist;

      //duration
      cout << "How long is the music in minutes?" << endl;
      int duration;
      cin >> duration;
    }
}
