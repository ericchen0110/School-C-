//Three rules:
//1. No global variables
//2. No strings. Not ever.
//3. You should avoid using a mouse when possible. Learn the shortcuts.


#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

int main()
{
  srand(time(NULL));

  //creating variables
  int random_num;
  int input = 0;
  
  while(true)
    {
      //generating the random number
      random_num = rand()%100;
      cout << "random number: " << random_num << endl;

      while(true)
	{
	  //getting input
	  cout << "Please enter a number from 0 to 100" << endl;
		  cin >> input;

	  //check if equal
	  if(input == random_num)
	    {
	      cout << "Congratulations! You guessed the correct number." << endl;
	      break;
	    }
	  //check if smaller
	  else if(input < random_num)
	    {
	      cout << "Your guess is too small! Try again" << endl;
	    }
	  //check if bigger
	  else if(input > random_num)
	    {
	      cout << "Your guess is too big! Try again" << endl;
	    }
	}

      //check if player wants to play again
      cout << "Do you want to play again? (y/n)" << endl;
      char again = ' ';
      cin >> again;
      if(again == 'n')
	{
	  break;
	}
    }

  cout << "Thank you for playing!" << endl;
  
  return 0;
}
