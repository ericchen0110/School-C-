#include <iostream>
#include <vector>
#include <map>

using namespace std;

class room{
 public:
  room(char* name, char* description);
  ~room();
  virtual map<char*, char*> get_map();
  virtual bool delete_item(char* name);
  virtual void add_item(char* name);
  virtual vector<char*> get_items();
  virtual char* get_name();
  virtual char* get_description();
  
 private:
  vector<char*> items;
  map<char*, char*> game_map;
};
