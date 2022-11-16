#include <iostream>

using namespace std;

class parent{
 public:
  parent(char* title, int year);
  virtual char* get_title();
  virtual int get_year();
 protected:
  char* title;
  int year;
};
