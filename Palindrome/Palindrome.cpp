//Arthur/Name: Eric Chen
//This program takes in a series of characters and determines if it's a palindrome
//Date: 9/14/2022

#include <iostream>
#include <cstring>
#include <ctype.h>

using namespace std;

int main()
{
  //read input
  char input[81];
  for(int i=0; i<81; i++)
    {
      input[i] = '0';
    }
  cin.get(input, 81);
  cin.get();

  //get rid of punctuations and spaces
  char processed[strlen(input)];
  char temp[1];
  int count = 0;

  for(int i=0; i<strlen(input); i++)
    {
      if(isalnum(input[i]))
	{
	  processed[count] = tolower(input[i]);
	  count++;
	}
    }

  //compare
  int yes = 0;
  for(int i=0; i<count; i++)
    {
      if(processed[i] != processed[count-1-i])
	{
	  yes = 1;
	  break;
	}
    }

  //print result
  if(yes == 0)
    {
      cout << "Palindrome" << endl;
    }
  else
    {
      cout << "Not a palindrome" << endl;
    }
  
  return 0;
}
