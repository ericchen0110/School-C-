//Written by: Eric Chen
//Date: 12/20/2022
//This is zuul, a text based adventure game

#include <iostream>
#include <cstring>
#include <vector>
#include <iterator>
#include <map>

#ifndef ROOM_H
#define ROOM_H
#include "room.h"
#endif

#ifndef KEY_H
#define KEY_H
#include "key.h"
#endif

using namespace std;

struct player {
  room* currentRoom = new room();
  vector<char*> inventory;
};

int main()
{
  //set up game
  //creating all 15 rooms
  room *r1 = new room();
  strcpy(r1->get_name(), "Starting Room");
  strcpy(r1->get_description(), "You woke up in a room, but you don't know where you are.");
  r1->set_locked(false);
  
  room *r2 = new room();
  strcpy(r2->get_name(), "Bedroom");
  strcpy(r2->get_description(), "This seems like someone's bedroom. The name tag on a notebook says: VVPP");
  r2->set_locked(true);
  strcpy(r2->get_key(), "bedroom key");
  
  room *r3 = new room();
  strcpy(r3->get_name(), "Corridor1");
  strcpy(r3->get_description(), "You are in a corridor, don't know where it leads to");
  r3->set_locked(false);
  
  room *r4 = new room();
  strcpy(r4->get_name(), "Storage Room");
  strcpy(r4->get_description(), "This seems like a storage room. You have a sense that something is hiding here");
  r4->set_locked(false);
  
  room *r5 = new room();
  strcpy(r5->get_name(), "Corridor2");
  strcpy(r5->get_description(), "You are in a corridor, don't know where it leads to.");
  r5->set_locked(false);
  
  room *r6 = new room();
  strcpy(r6->get_name(), "Bathroom");
  strcpy(r6->get_description(), "This seems like a bathroom. It stinks and you want to leave asap.");
  r6->set_locked(false);
  
  room *r7 = new room();
  strcpy(r7->get_name(), "Entry to the basement");
  strcpy(r7->get_description(), "You entered the basement");
  r7->set_locked(true);
  strcpy(r7->get_key(), "basement key");

  room *r8 = new room();
  strcpy(r8->get_name(), "Closet");
  strcpy(r8->get_description(), "Something is in the closet");
  r8->set_locked(false);

  room *r9 = new room();
  strcpy(r9->get_name(), "Office");
  strcpy(r9->get_description(), "This seems like an office, but why would anyone work in the basement?");
  r9->set_locked(false);

  room *r10 = new room();
  strcpy(r10->get_name(), "Secret chamber");
  strcpy(r10->get_description(), "The key to the exit is here! You can get out!");
  r10->set_locked(true);
  strcpy(r10->get_key(), "secret chamber key");

  room *r11 = new room();
  strcpy(r11->get_name(), "Lab");
  strcpy(r11->get_description(), "This looks like a biology lab. What is VVPP doing here?");
  r11->set_locked(false);

  room *r12 = new room();
  strcpy(r12->get_name(), "Strong Box");
  strcpy(r12->get_description(), "Some files are in the strong box. You found a key too.");
  r12->set_locked(true);
  strcpy(r12->get_key(), "strong box key");

  room *r13 = new room();
  strcpy(r13->get_name(), "Drawer");
  strcpy(r13->get_description(), "A key is in the drawer");
  r13->set_locked(false);

  room *r14 = new room();
  strcpy(r14->get_name(), "Livingroom");
  strcpy(r14->get_description(), "You are in the living room");
  r14->set_locked(false);

  room *r15 = new room();
  strcpy(r15->get_name(), "Exit");
  strcpy(r15->get_description(), "Congrats! You are free now!");
  r15->set_locked(true);
  strcpy(r15->get_key(), "exit key");

  //adding items to these rooms

  //key to room 2
  char *k2 = new char[100];
  strcpy(k2, "bedroom key");
  r4->add_item(k2);

  //key to room 7
  char *k7 = new char[100];
  strcpy(k7, "basement key");
  r8->add_item(k7);

  //key to room 15
  char *k15 = new char[100];
  strcpy(k15, "exit key");
  r10->add_item(k15);

  //key to room 10
  char *k10 = new char[100];
  strcpy(k10, "secret chamber key");
  r12->add_item(k10);
  
  //key to room 12
  char *k12 = new char[100];
  strcpy(k12, "strong box key");
  r13->add_item(k12);

  //add exits
  r1->set_east(true);
  r1->set_north(true);
  r1->set_west(true);
  r1->set_south(true);
  r1->set_exits('e', r2->get_name());
  r1->set_exits('n', r4->get_name());
  r1->set_exits('w', r14->get_name());
  r1->set_exits('s', r3->get_name());

  r2->set_east(true);
  r2->set_west(true);
  r2->set_south(true);
  r2->set_north(false);
  r2->set_exits('w', r1->get_name());
  r2->set_exits('e', r7->get_name());
  r2->set_exits('s', r5->get_name());
  
  r3->set_north(true);
  r3->set_south(true);
  r3->set_west(false);
  r3->set_east(false);
  r3->set_exits('n', r1->get_name());
  r3->set_exits('s', r6->get_name());

  r4->set_east(false);
  r4->set_north(false);
  r4->set_west(false);
  r4->set_south(true);
  r4->set_exits('s', r1->get_name());

  r5->set_east(true);
  r5->set_north(true);
  r5->set_west(false);
  r5->set_south(false);
  r5->set_exits('n', r2->get_name());
  r5->set_exits('e', r8->get_name());

  r6->set_east(false);
  r6->set_north(true);
  r6->set_west(false);
  r6->set_south(false);
  r6->set_exits('n', r3->get_name());

  r7->set_east(true);
  r7->set_north(true);
  r7->set_west(true);
  r7->set_south(false);
  r7->set_exits('w', r2->get_name());
  r7->set_exits('e', r11->get_name());
  r7->set_exits('n', r9->get_name());

  r8->set_east(false);
  r8->set_north(false);
  r8->set_west(true);
  r8->set_south(false);
  r8->set_exits('w', r5->get_name());

  r9->set_east(false);
  r9->set_north(false);
  r9->set_west(false);
  r9->set_south(true);
  r9->set_exits('s', r7->get_name());

  r10->set_east(false);
  r10->set_north(false);
  r10->set_west(false);
  r10->set_south(true);
  r10->set_exits('s', r14->get_name());

  r11->set_east(false);
  r11->set_north(true);
  r11->set_west(true);
  r11->set_south(false);
  r11->set_exits('w', r7->get_name());
  r11->set_exits('n', r12->get_name());

  r12->set_east(false);
  r12->set_north(false);
  r12->set_west(false);
  r12->set_south(true);
  r12->set_exits('s', r11->get_name());

  r13->set_east(false);
  r13->set_north(true);
  r13->set_west(false);
  r13->set_south(false);
  r13->set_exits('n', r14->get_name());

  r14->set_east(true);
  r14->set_north(true);
  r14->set_west(true);
  r14->set_south(true);
  r14->set_exits('w', r15->get_name());
  r14->set_exits('n', r10->get_name());
  r14->set_exits('e', r1->get_name());
  r14->set_exits('s', r13->get_name());

  r15->set_east(true);
  r15->set_north(false);
  r15->set_west(false);
  r15->set_south(false);
  r15->set_exits('e', r14->get_name());

  //add all these rooms to a map
  map<char*, room*> room_map;
  room_map[r1->get_name()] = r1;
  room_map[r2->get_name()] = r2;
  room_map[r3->get_name()] = r3;
  room_map[r4->get_name()] = r4;
  room_map[r5->get_name()] = r5;
  room_map[r6->get_name()] = r6;
  room_map[r7->get_name()] = r7;
  room_map[r8->get_name()] = r8;
  room_map[r9->get_name()] = r9;
  room_map[r10->get_name()] = r10;
  room_map[r11->get_name()] = r11;
  room_map[r12->get_name()] = r12;
  room_map[r13->get_name()] = r13;
  room_map[r14->get_name()] = r14;
  room_map[r15->get_name()] = r15;

  
  //print intro to the game
  cout << "Welcome to Zuul! This is a text based adventure game." << endl;

  //set initial starting room
  player* myPlayer = new player();
  myPlayer->currentRoom = r1;

  while(true)
    {
      //print out basic info of the room
      cout << "_____________________________________________________________________" << endl;
      cout << "You are currently in the " << (myPlayer->currentRoom)->get_name() << endl;
      cout << (myPlayer->currentRoom)->get_description() << endl;

      //check if game over
      if(strcmp((myPlayer->currentRoom->get_name()), "Exit") == 0)
	{
	  cout << "game over" << endl;
	  break;
	}
    
      
      if((myPlayer->currentRoom->get_items()).size() == 0)
	{
	  cout << "There are no items in this room" << endl;
	}
      else
	{
	  cout << "There are following items in the room: ";
	  for(int i=0; i< myPlayer->currentRoom->get_items().size(); i++)
	    {
	      cout << myPlayer->currentRoom->get_items()[i] << "     ";
	    }
	  cout << endl;
	}

      //print out exits
      cout << "This room has the follwing exits:" << endl;
      if(myPlayer->currentRoom->get_north())
	{
	  cout << "North: " << myPlayer->currentRoom->get_exits()['n'] << endl;
	}

      if(myPlayer->currentRoom->get_south())
        {
          cout << "South: " << myPlayer->currentRoom->get_exits()['s'] << endl;
        }

      if(myPlayer->currentRoom->get_east())
        {
          cout << "East: " << myPlayer->currentRoom->get_exits()['e'] << endl;
        }

      if(myPlayer->currentRoom->get_west())
        {
          cout << "West: " << myPlayer->currentRoom->get_exits()['w'] << endl;
        }
      
      cout << "\nWhat do you want to do?(INVENTORY, PICK, DROP, MOVE, QUIT)" << endl;

      char input[100];
      cin.get(input, 100);
      cin.get();

      if(strcmp(input, "INVENTORY") == 0)
	{
	  //print out inventory
	  if(myPlayer->inventory.size() == 0)
	    {
	      cout << "\nYou have no item in your inventory" << endl;
	    }
	  else
	    {
	      cout << "\nYou have the following items in you inventory: ";
	      for(int i=0; i < myPlayer->inventory.size(); i++)
		{
		  cout << myPlayer->inventory[i] << "    ";
		}
	      cout << endl;
	    }
	}
      else if(strcmp(input, "PICK") == 0)
	{
	  //pick stuff into inventory
	  cout << "Which item do you want to pick up?" << endl;
	  char *input1 = new char[100];
	  cin.get(input1, 100);
	  cin.get();
	  bool exist = false;
	  
	  for(int i=0; i < myPlayer->currentRoom->get_items().size(); i++)
	    {
	      if(strcmp(myPlayer->currentRoom->get_items()[i], input1) == 0)
		{
		  exist = true;
		  myPlayer->currentRoom->delete_item(input1);
		  myPlayer->inventory.push_back(input1);
		  cout << endl << "You've picked up " << input1 << endl;
		}
	    }
	  if(!exist)
	    {
	      cout << "\nThe item you typed does not exist" << endl;
	    }
	}
      else if(strcmp(input, "DROP") == 0)
	{
	  //Drop items from inventory to the room
	  cout << "Which item do you want to drop in the room?" << endl;
	  char* input2 = new char[100];
	  cin.get(input2, 100);
	  cin.get();
	  bool exist = false;
	  vector<char*>::iterator inventory_I;
	  
	  for(inventory_I = myPlayer->inventory.begin(); inventory_I < myPlayer->inventory.end(); inventory_I++)
	    {
	      if(strcmp((*inventory_I), input2) == 0)
		{
		  exist = true;
		  //delete from inventory
		  myPlayer->inventory.erase(inventory_I);

		  //add to the room
		  myPlayer->currentRoom->add_item(input2);

		  cout << endl << "You've dropped " << input2 << endl;
		}
	    }

	  if(!exist)
	    {
	      cout << "\nThe item you typed does not exist in your inventory" << endl;
	    }
	}
      else if(strcmp(input, "MOVE") == 0)
	{
	  //move to another room
	  cout << "Enter the direciton of the room you want to go to.(north, south, west, east)" << endl;
	  char* input3 = new char[100];
	  cin.get(input3, 100);
	  cin.get();

	  //check north
	  if(strcmp(input3, "north") == 0)
	    {
	      if(myPlayer->currentRoom->get_north())
		{
		  char* room_name = myPlayer->currentRoom->get_exits()['n'];
		  room *next_room = room_map[room_name];
		  //check if the room is locked
		  if(next_room->get_locked())
		    {
		      bool have_key = false;
		      vector<char*>::iterator inventory_I;
		      for(inventory_I = myPlayer->inventory.begin(); inventory_I < myPlayer->inventory.end(); inventory_I++)
			{
			  if(strcmp((*inventory_I), next_room->get_key()) == 0)
			    {
			      have_key = true;
			    }
			}
		      if(!have_key)
			{
			  cout << "\nThis room is locked. Go to other rooms to find the key to this room." << endl;
			}
		      else
			{
			  myPlayer->currentRoom = next_room;
			}
		    }
		  else
		    {
		      myPlayer->currentRoom = next_room;
		    }
		  }
	      else
		{
		  cout << "The exit you typed does not exist" << endl;
		}
	    }
	  //check south
	  else if(strcmp(input3, "south") == 0)
            {
              if(myPlayer->currentRoom->get_south())
                {
                  char* room_name = myPlayer->currentRoom->get_exits()['s'];
                  room *next_room = room_map[room_name];
                  //check if the room is locked
                  if(next_room->get_locked())
                    {
                      bool have_key = false;
                      vector<char*>::iterator inventory_I;
                      for(inventory_I = myPlayer->inventory.begin(); inventory_I < myPlayer->inventory.end(); inventory_I++)
                        {
                          if(strcmp((*inventory_I), next_room->get_key()) == 0)
                            {
                              have_key = true;
                            }
                        }
                      if(!have_key)
                        {
                          cout << "\nThis room is locked. Go to other rooms to find the key to this room." << endl;
                        }
                      else
                        {
                          myPlayer->currentRoom = next_room;
                        }
                    }
                  else
                    {
                      myPlayer->currentRoom = next_room;
                    }
                  }
              else
                {
                  cout << "The exit you typed does not exist" << endl;
                }
            }
	  //check west
	  else if((strcmp(input3, "west") == 0))
            {
              if(myPlayer->currentRoom->get_west())
                {
                  char* room_name = myPlayer->currentRoom->get_exits()['w'];
                  room *next_room = room_map[room_name];
                  //check if the room is locked
                  if(next_room->get_locked())
                    {
                      bool have_key = false;
                      vector<char*>::iterator inventory_I;
                      for(inventory_I = myPlayer->inventory.begin(); inventory_I < myPlayer->inventory.end(); inventory_I++)
                        {
                          if(strcmp((*inventory_I), next_room->get_key()) == 0)
                            {
                              have_key = true;
                            }
                        }
                      if(!have_key)
                        {
                          cout << "\nThis room is locked. Go to other rooms to find the key to this room." << endl;
                        }
                      else
                        {
                          myPlayer->currentRoom = next_room;
                        }
                    }
                  else
                    {
                      myPlayer->currentRoom = next_room;
                    }
                  }
              else
                {
                  cout << "The exit you typed does not exist" << endl;
                }
            }
	    //check east
	  else if((strcmp(input3, "east") == 0))
            {
              if(myPlayer->currentRoom->get_east())
                {
                  char* room_name = myPlayer->currentRoom->get_exits()['e'];
                  room *next_room = room_map[room_name];
                  //check if the room is locked
                  if(next_room->get_locked())
                    {
                      bool have_key = false;
                      vector<char*>::iterator inventory_I;
                      for(inventory_I = myPlayer->inventory.begin(); inventory_I < myPlayer->inventory.end(); inventory_I++)
                        {
                          if(strcmp((*inventory_I), next_room->get_key()) == 0)
                            {
                              have_key = true;
                            }
                        }
                      if(!have_key)
                        {
                          cout << "\nThis room is locked. Go to other rooms to find the key to this room." << endl;
                        }
                      else
                        {
                          myPlayer->currentRoom = next_room;
                        }
                    }
                  else
                    {
                      myPlayer->currentRoom = next_room;
                    }
                  }
              else
                {
                  cout << "The exit you typed does not exist" << endl;
                }
            }

	}
      else if(strcmp(input, "QUIT") == 0)
	{
	  //Quit game
	  cout << "\nIt seems like you've quit. You are trapped in VVPP's house forever." << endl;
	  break;
	}
      else
	{
	  cout << "Please input a valid commend. The commends are: " << endl;
	  cout << "INVENTORY   PICK   DROP   MOVE   QUIT" << endl;
	}
    }
}
