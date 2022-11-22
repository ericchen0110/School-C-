#include <iostream>
#include <cstring>

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

using namespace std;

int main()
{
  char input[3];
  strcpy(input, "hi");
  parent* new_p = new parent(input, 2);
  cout << "Parent title: " << new_p->get_title() << endl;
  cout << "Parent year: " << new_p->get_year() << endl;

  char input1[3];
  char input2[6];
  strcpy(input2, "child");
  strcpy(input1, "oh");
  video_game* new_game = new video_game(input1, 2, input2, 3.3);
  cout << "Video Game Title: " << new_game->get_title() << endl;
  cout << "video game year: " << new_game->get_year() << endl;
  cout << "video game publisher: " << new_game->get_publisher() << endl;
  cout << "video game rating: " << new_game->get_rating() << endl;

  music* new_music = new music(input, 3, input1, input2, 60);
  cout << "music title: " << new_music->get_title() << endl;
}
