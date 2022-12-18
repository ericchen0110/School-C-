#include <iostream>
#include <vector>
#include <cstring>
#include <iterator>

#ifndef ROOM_H
#define ROOM_H
#include "room.h"
#endif

using namespace std;

room::room(char* name, char* description)
{
  strcpy(this->name, name);
  strcpy(this->description, description);
}

vector<char*> room::get_items()
{
  return items;
}

char* room::get_name()
{
  return name;
}

char* room::get_description()
{
  return description;
}

map<char*, char*> room::get_map()
{
  return game_map;
}

bool room::delete_item(char* name)
{
  vector<char*>::iterator I;
  for(I = items.begin(); I != items.end(); I++)
    {
      if(strcmp((*I), name) == 0)
	{
	  items.erase(I);
	  return true;
	}
    }

  cout << "Item not found\n";
  return false;
}

void room::add_item(char* name)
{
  items.push_back(name);
}
