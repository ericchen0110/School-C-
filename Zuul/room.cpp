#include <iostream>
#include <vector>
#include <cstring>
#include <iterator>

#ifndef ROOM_H
#define ROOM_H
#include "room.h"
#endif

#ifndef KEY_H
#define KEY_H
#include "key.h"
#endif

using namespace std;

room::room()
{
  
}

room::~room()
{
  delete[] name;
  delete[] description;
  
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

map<char, char*> room::get_exits()
{
  return exits;
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
  char* input = new char[100];
  strcpy(input, name);
  items.push_back(input);
}

bool room::get_locked()
{
  return locked;
}

void room::set_locked(bool setting)
{
  locked = setting;
}

void room::set_exits(char direction, char* name)
{
  exits[direction] = name;
}

void room::set_key(char* name)
{
  key = name;
}

char* room::get_key()
{
  return key;
}

void room::set_north(bool setting)
{
  north = setting;
}

bool room::get_north()
{
  return north;
}

void room::set_west(bool setting)
{
  west = setting;
}

bool room::get_west()
{
  return west;
}

void room::set_south(bool setting)
{
  south = setting;
}

bool room::get_south()
{
  return south;
}

void room::set_east(bool setting)
{
  east = setting;
}

bool room::get_east()
{
  return east;
}
