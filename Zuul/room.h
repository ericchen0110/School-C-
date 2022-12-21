#include <iostream>
#include <vector>
#include <map>

using namespace std;

class room{
 public:
  room();
  ~room();
  virtual map<char, char*> get_exits();
  virtual void set_exits(char direction, char* name); 
  virtual bool delete_item(char* name);
  virtual void add_item(char* name);
  virtual vector<char*> get_items();
  virtual char* get_name();
  virtual char* get_description();
  virtual bool get_locked();
  virtual void set_locked(bool setting);
  virtual void set_key(char* name);
  virtual char* get_key();

  virtual void set_north(bool setting);
  virtual bool get_north();
  virtual void set_west(bool setting);
  virtual bool get_west();
  virtual void set_south(bool setting);
  virtual bool get_south();
  virtual void set_east(bool setting);
  virtual bool get_east();

  
 private:
  char* name = new char[100];
  char* description = new char[1000];
  vector<char*> items;
  map<char, char*> exits;
  bool locked;
  char* key = new char[100];
  bool north;
  bool east;
  bool west;
  bool south;
};
