#include <iostream>
#include <cstring>
#include <vector>
#include <typeinfo>

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
void search(vector<parent*> *media_vector);
void Delete(vector<parent*> *media_vector);

int main()
{
  //input
  char input[81];
  cout << "What do you want to do? (ADD, SEARCH, DELETE, QUIT)" << endl;
  cin.get(input, 81);
  cin.get();

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
      search(media_vector);
    }
  else if(strcmp(input, "DELETE") == 0)
    {
      //DELETE
      Delete(media_vector);
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
  cin.get(type, 81);
  cin.get();
  
  //ask for input to each field
  //title
  cout << "What is the title?" << endl;
  char title[81];
  cin.get(title, 81);
  cin.get();

  //year
  cout << "What is the year?" << endl;
  int year;
  cin >> year;
  cin.get();
  
  if(strcmp(type, "movie") == 0)
    {
      //movie
      
      //director
      cout << "What is the name of the director?" << endl;
      char director[81];
      cin.get(director, 81);
      cin.get();

      //duration
      cout << "How long is the movie in minutes?" << endl;
      int duration;
      cin >> duration;
      cin.get(); 

      //rating
      cout << "What is the rating?" << endl;
      float rating;
      cin >> rating;
      cin.get();

      movie* new_movie = new movie(title, year, rating, director, duration);
      media_vector->push_back(new_movie);

      cout < new_movie->get_type() << endl;
    }
  else if(strcmp(type, "video_game") == 0)
    {
      //video game
      //publisher
      cout << "What is the name of the publisher?" << endl;
      char publisher[81];
      cin.get(publisher, 81);
      cin.get();

      //rating
      cout << "What is the rating?" << endl;
      float rating;
      cin >> rating;
      cin.get();

      video_game* new_videogame =  new video_game(title, year, publisher, rating);
      media_vector->push_back(new_videogame);
    }
  else if(strcmp(type, "music") == 0)
    {
      //music
      //artist
      cout << "What is the name of the artist?" << endl;
      char artist[81];
      cin.get(artist, 81);
      cin.get();
      
      //duration
      cout << "How long is the music in minutes?" << endl;
      int duration;
      cin >> duration;
      cin.get();

      //publisher
      cout << "What is the name of the publisher?" << endl;
      char publisher[81];
      cin.get(publisher, 81);
      cin.get();

      music* new_music = new music(title, year, artist, publisher, duration);
      media_vector->push_back(new_music);
    }
}

void search(vector* <parent*> media_vector)
{
  //title or year
  cout << "Do you want to search by title or year?" << endl;
  char input[81];
  cin.get(input, 81);
  cin.get();

  if(strcmp(input, "title") = 0)
    {
      //title
      cout << "What is the title?" << endl;
      char input_title[81];
      cin.get(input_title, 81);
      cin.get();
      
      /*for(int i=0; i < media_vector->size(); i++)
	{
	  if(strcmp((*media_vector)[i]->title, input_title) = 0)
	    {
	      cout 
	    }
	}*/
    }
  else if(strcmp(input, "year") = 0)
    {
      //year
    }
}

void Delete(vector* <parent*> media_vector)
{
  
}
