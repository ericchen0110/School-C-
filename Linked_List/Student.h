#include <iostream>

using namespace std;

class Student{
 public:
  Student(char* first_name, char* last_name, int id, float gpa);
  ~Student();
  virtual char* get_first_name();
  virtual char* get_last_name();
  virtual int get_id();
  virtual float get_gpa();

 private:
  char *first_name = new char[100];
  char *last_name = new char[100];
  int id;
  float gpa;
};
