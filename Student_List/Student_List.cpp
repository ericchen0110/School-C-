#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

//defin the struct
struct Student {
  char *fist_name;
  char *last_name;
  int id;
  float gpa;
};

//define functions
void add(vector<Student*> *student_vector);
void print_fun(vector<Student*> *student_vector);

int main()
{
  vector<Student*> student_vector;
  
  //get input
  char *input;
  cin >> input;
  if(strcmp(input, "ADD") == 0)
    {
      //ADD
      add(&student_vector);
    }
  else if(strcmp(input , "PRINT") == 0)
    {
      //PRINT
      print_fun(&student_vector);
    }
}

void add(vector<Student*> *student_vector)
{
  //define all variables
  char first_name[21];
  char last_name[21];
  int id;
  int GPA;

  //get input
  cout << "First name: ";
  cin.get(first_name, 20);
  cout << "\nLast name: ";
  cin >> *last_name;
  cout << "\nStudent ID: ";
  cin >> id;
  cout << "\nGPA: ";
  cin >> GPA;
}

void print_fun(vector<Student*> *student_vector)
{
  
}
