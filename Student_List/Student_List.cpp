#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

//defin the struct
struct Student {
  char *first_name = new char[80];
  char *last_name = new char[80];
  int id;
  float gpa;
};

//define functions
void add(vector<Student*> *student_vector);
void print_fun(vector<Student*> *student_vector);

int main()
{
  while(true)
    { 
      cout << "Type ADD, PRINT, or DELETE" << endl;
      //get input
      char *input;
      cin >> input;
      vector<Student*> *student_vector = new vector<Student*>();
      if(strcmp(input, "ADD") == 0)
	{
	  //ADD
	  add(student_vector);
	}
      else if(strcmp(input , "PRINT") == 0)
	{
	  //PRINT
	  print_fun(student_vector);
	}
    }
}

void add(vector<Student*> *student_vector)
{
  //define all variables
  char first_name[80];
  char last_name[80];
  int id;
  float GPA;

  
  //get input
  cout << "First name: ";
  cin >> first_name;
  cout << "Last name: ";
  cin >> last_name;
  cout << "Student ID: "; 
  cin >> id;
  cout << "GPA: ";
  cin >> GPA;

  //Add new student
  Student *new_student = new Student();
  strcpy(new_student->first_name, first_name);
  new_student->last_name = last_name;
  new_student->id = id;
  new_student->gpa = GPA;
  
  //add to the vector
  student_vector->push_back(new_student);
}

void print_fun(vector<Student*> *student_vector)
{
  cout << "size: " << student_vector->size() << endl;
  for(int i=0; i<student_vector->size(); i++)
    {
       cout << (*student_vector)[i]->first_name << " " << (*student_vector)[i]->last_name << ", " << (*student_vector)[i]->id << ", " << (*student_vector)[0]->gpa << endl;
    }
	return;
}
