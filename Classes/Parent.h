#include <iostream>

using namespace std;

class parent{
 public:
  parent(char* title, int year);
  virtual char* get_title();
  virtual int get_year();
  virtual int get_type();
 protected:
  char* title = new char[81];
  int year;
  int type;
};
