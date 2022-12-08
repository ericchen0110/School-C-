#include <iostream>

using namespace std;

class room{
 public:
  room(char* name);
  virtual char** get_items();
  virtual char* get_name();
  virtual room* get_north();
  virtual room* get_south();
  virtual room* get_west();
  virtual room* get_east();
  
 protected:
  char items = new char[][];
  char* name = new char[81];
  room *north;
  room *south;
  room *west;
  room *east;
};
