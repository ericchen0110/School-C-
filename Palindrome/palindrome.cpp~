#include <iostream>
#include <cstring>
#include <ctype.h>

using namespace std;

int main()
{
  //read input
  char input[80];
  for(int i=0; i<80; i++)
    {
      input[i] = '0';
    }
  cin.get(input, 80);
  cin.get();

  //get rid of punctuations and spaces
  char processed[80];
  char temp[1];
  int count = 0;
  for(int i=0; i<80; i++)
    {
      temp[0] = input[i];
      if(temp[0] == '0')
	{
	  break;
	}
      else if(isalpha(temp[0]))
	{
	  strncat(processed, temp, 1);
	  count++;
	}
    }

  //compare
  cout << processed[0] << endl;
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
