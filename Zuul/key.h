#include <iostream>
#include <cstring>

using namespace std;

class key{
 public:
  key();
  ~key();
  virtual char* get_name();
  virtual int get_number();
  virtual void set_number(int setting);

 private:
  char* name = new char[100];
  int number;
};
