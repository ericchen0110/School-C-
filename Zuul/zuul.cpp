#include <iostream>
#include <cstring>
#include <vector>
#include <iterator>
#include <map>

#ifndef ROOM_H
#define ROOM_H
#include "room.h"
#endif

using namespace std;

struct player {
  room* currentRoom = new room();
  vector<char*>* inventory;
  vector <room*> roomList;
  char* input = new char[80];
};

void makeGame();

int main()
{
  makeGame();
}

void makeGame()
{
  
}
