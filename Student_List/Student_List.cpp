//Name: Eric Chen
//Date: 10/19/2022
//This program

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
void delete_fun(vector<Student*> *student_vector);

int main()
{
  //create the vector
  vector<Student*> *student_vector = new vector<Student*>();
  
  while(true)
    { 
      cout << "Type ADD, PRINT, or DELETE. Type QUIT if you want to quit." << endl;
      //get input
      char *input;
      cin >> input;
      
      if(strcmp(input, "ADD") == 0)
	{
	  //ADD
	  add(student_vector);
	}
      else if(strcmp(input, "PRINT") == 0)
	{
	  //PRINT
	  print_fun(student_vector);
	}
      else if(strcmp(input, "DELETE") == 0)
	{
	  //DELETE
	  delete_fun(student_vector);
	}
      else if(strcmp(input, "QUIT") == 0)
	{
	  //break
	  break;
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
  strcpy(new_student->last_name, last_name);
  new_student->id = id;
  new_student->gpa = GPA;
  
  //add to the vector
  student_vector->push_back(new_student);

  //print out message
  cout << "Student added" << endl;
}

void print_fun(vector<Student*> *student_vector)
{
  for(int i=0; i<student_vector->size(); i++)
    {
      //print
       cout << (*student_vector)[i]->first_name << " " << (*student_vector)[i]->last_name << ", " << (*student_vector)[i]->id << ", " << (*student_vector)[i]->gpa << endl;
    }
	return;
}

void delete_fun(vector<Student*> *student_vector)
{
  //get input
  int id;
  cout << "Student ID of the student that you want to DELETE: ";
  cin >> id;

  bool exist = false;
  for(int i=0; i<student_vector->size(); i++)
    {
      if((*student_vector)[i]->id == id)
	{
	  //delete student
	  exist = true;
	  delete *(student_vector->begin()+i);
	  student_vector->erase(student_vector->begin()+i);
	}
    }

  //print out message
  if(!exist)
    {
      cout << "The student does not exist" << endl;
    }
  else
    {
      cout << "Student deleted" << endl;
    }
  
  return;
}
