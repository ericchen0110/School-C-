#include <iostream>
#include <cstring>
#include "parent.h"

using namespace std;

int main()
{
  char input[3];
  strcpy(input, "hi");
  parent* new_p = new parent(input, 2);
  cout << "Parent title: " << new_p->get_title() << endl;
  cout << "Parent year: " << new_p->get_year() << endl;
}
