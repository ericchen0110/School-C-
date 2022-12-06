//This is the main cpp file of the Classes program, users can add, search, and delete medias in the database
//Date: December 3, 2022
//Written by Eric Chen

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
void Delete(vector<parent*> *media_vector, vector<int> vec);
void Print(parent* media);

int main()
{
  //create vector
  vector<parent*> *media_vector = new vector<parent*>();
  
  while(true)
    {
      for(int i=0; i<70; i++)
	{
	  cout << "-";
	}
      cout << endl;
      
      //input
      char input[81];
      cout << "What do you want to do? (ADD, SEARCH, QUIT, you can delete the media in the SEARCH function)" << endl;
      cin.get(input, 81);
      if(!cin)
	{
	  cin.clear();
	}
      cin.get();

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
      else if(strcmp(input, "QUIT") == 0)
	{
	  //QUIT
	  break;
	}
    }
}

void add(vector<parent*> *media_vector)
{
  char type[81];
  while(true)
    {
      //media type
      cout << "What type of media do you want to add? (movie, music, video_game)" << endl;
      cin.get(type, 81);
      if(!cin)
	{
	  cin.clear();
	}
      cin.get();

      if(strcmp(type, "movie") != 0 && strcmp(type, "music") != 0 && strcmp(type, "video_game") != 0)
	{
	  cout << "\nPlease enter movie, music, or video_game" << endl;
	}
      else
	{
	  break;
	}
    }
      
  //ask for input to each field
  //title
  char title[81];
  cout << "What is the title?" << endl;
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
      cin.clear();
      cin.get();

      int duration;
      //duration
      cout << "How long is the movie in minutes?" << endl;
      cin >> duration;
      cin.get();

      //rating
      cout << "What is the rating?" << endl;
      float rating;
      cin >> rating;
      cin.get();

      movie* new_movie = new movie(title, year, rating, director, duration);
      media_vector->push_back(new_movie);
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

void search(vector <parent*> *media_vector)
{
  //title or year
  cout << "Do you want to search by title or year?" << endl;
  char input[81];
  cin.get(input, 81);
  cin.get();
  vector <int> position;
  bool exist = false;

      if(strcmp(input, "title") == 0)
	{
	  //title
	  cout << "What is the title?" << endl;
	  char input_title[81];
	  cin.get(input_title, 81);
	  cin.get();

	  for(int i=0; i < media_vector->size(); i++)
	    {
	      if(strcmp((*media_vector)[i]->get_title(), input_title) == 0)
		{
		  position.push_back(i);
		  if((*media_vector)[i]->get_type() == 1)
		    {
		      //video game
		      Print((*media_vector)[i]);
		    }
		  else if((*media_vector)[i]->get_type() == 2)
		    {
		      //movie
		      Print((*media_vector)[i]);
		    }
		  else if((*media_vector)[i]->get_type() == 3)
		    {
		      //music
		      Print((*media_vector)[i]);
		    }
		  exist = true;
		}
	    }
	}
      else if(strcmp(input, "year") == 0)
	{
	  
	  //year
	  cout << "What is the year?" << endl;
	  int input_year;
	  cin >> input_year;
	  cin.get();

	  for(int i=0; i < media_vector->size(); i++)
	    {
	      position.push_back(i);
	      
	      if((*media_vector)[i]->get_year() == input_year)
		{
		  if((*media_vector)[i]->get_type() == 1)
		    {
		      //video game
		      Print((*media_vector)[i]);
		    }
		  else if((*media_vector)[i]->get_type() == 2)
		    {
		      //movie
		      Print((*media_vector)[i]);
		    }
		  else if((*media_vector)[i]->get_type() == 3)
		    {
		      //music
		      Print((*media_vector)[i]);
		    }
		  exist = true;
		}
	    }
	}

      if(exist)
	{
	  //delete
	  char delete_input[81];
	  cout << "\nDo you want to delete these media? (Yes or No)" << endl;
	  cin.get(delete_input, 81);
	  cin.get();

	  if(strcmp(delete_input, "Yes") == 0)
	    {
	      Delete(media_vector, position);
	    }
	}
      else if(!exist)
	{
	  cout << "\nThe media does not exist" << endl;
	}
}

void Print(parent* media)
{
  cout << endl;
  
  if(media->get_type() == 1)
    {
      //video game
      video_game *v = static_cast<video_game*>(media);

      //print
      cout << "Type: video game" << endl;
      cout << "Title: " << v->get_title() << endl;
      cout << "Year: " << v->get_year() << endl;
      cout << "Publisher: " << v->get_publisher() << endl;
      cout << "Rating: " << v->get_rating() << endl;
    }
  else if(media->get_type() == 2)
    {
      //movie
      movie *v = static_cast<movie*>(media);
      
      cout << "Type: movie" << endl;
      cout << "Title: " << v->get_title() << endl;
      cout << "Year: " << v->get_year() << endl;
      cout << "Director: " << v->get_director() << endl;
      cout << "Duration: " << v->get_duration() << " minutes" << endl;
      cout << "Rating: " << v->get_rating() << endl;
    }
  else if(media->get_type() == 3)
    {
      //music
      music *v = static_cast<music*>(media);
      
      cout << "Type: music" << endl;
      cout << "Title: " << v->get_title() << endl;
      cout << "Year: " << v->get_year() << endl;
      cout << "Artist: " << v->get_artist() << endl;
      cout << "Duration: " << v->get_duration() << " minutes" << endl;
      cout << "Publisher: " << v->get_publisher() << endl;
    }

}

 void Delete(vector <parent*> *media_vector, vector <int> vec)
{
  vector<parent*>:: iterator mIterator;

  for(int i=0; i<vec.size(); i++)
    {
      for(mIterator = media_vector->begin(); mIterator < media_vector->end(); mIterator += vec[i])
	{
	  Print(*mIterator);
	  cout << "\nDo you want to delete this media? (Yes or No)" << endl;
	  char input[81];
	  cin.get(input, 81);
	  cin.get();
	  
	  if(strcmp(input, "Yes") == 0)
	    {
	      //video game
	      if((*mIterator)->get_type() == 1)
		{ 
		  video_game *v = static_cast<video_game*>(*mIterator);
		  delete v;
		  media_vector->erase(mIterator);
		}
	      else if((*mIterator)->get_type() == 2)
		{
		  //movie
		  movie *m = static_cast<movie*>(*mIterator);
		  delete m;
		  media_vector->erase(mIterator);
		}
	      else if((*mIterator)->get_type() == 3)
		{
		  //music
		  music *m = static_cast<music*>(*mIterator);
		  delete m;
		  media_vector->erase(mIterator);
		}
	    }
	  else
	    {
	      break;
	    }
	}
    }
}
