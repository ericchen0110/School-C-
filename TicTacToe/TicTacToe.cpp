//Arthor name: Eric Chen
//Data: 9/22/2022
//This program allows to play tic tac toe and checks for wins. 

#include <iostream>
#include <cstring>

using namespace std;

//define all functions
void setBoard(char board[4][4]);
void printBoard(char board[4][4]);
void play(char board[4][4], char *turn);
char checkWin(char board[4][4], char *turn);

int main()
{
  char board[4][4];
  int X_win = 0;
  int Y_win = 0;
  int count;

  while(true)
    {
      count = 0;
      
  //0 is X, 1 is O
  char turn = 'X';

  //set the board
  setBoard(board);
  
  while(true)
    {
      printBoard(board);

      play(board, &turn);

      count++;
      
      //check win
      if(checkWin(board, &turn) == 'X')
	{
	  cout << "X won!" << endl;
	  X_win++;
	  break;
	}
      else if(checkWin(board, &turn) == 'O')
	{
	  cout << "O won!" << endl;
	  Y_win++;
	  break;
	}

      //check tie
      if(count == 9)
	{
	  cout << "Tie!" << endl;
	  break;
	}
      
      //change turns
      if(turn == 'X')
	{
	  turn = 'O';
	}
      else if(turn == 'O')
	{
	  turn = 'X';
	}
    }

  //Print out number of wins
  cout << "X won " << X_win << " times" << endl;
  cout << "Y won " << Y_win << " times" << endl;
  
  //ask if want to play again
  cout << "Do you want to play again? (y/n)" << endl;
  char input;
  while(true)
    {
      cin >> input;
      if(input == 'n' || input == 'y')
	{
	  break;
	}
    }
    if(input == 'n')
      {
        break;
      }
  }

  return 0;
}

void play(char board[4][4], char *turn)
{
  while(true)
    {
      char input[100];
      cin.getline(input, 100);

      //check if is correct input
      if(strlen(input) == 2 &&
	 (input[0] == 'a' || input[0] == 'b' || input[0] == 'c') && (input[1] == '1' || input[1] == '2' || input[1] == '3'))
	{
	  if(board[input[0]-96][input[1]-48] == ' ')
	    {
	      //X turn
	      if(*turn == 'X')
		{
		  board[input[0]-96][input[1]-48] = 'X';
		}
	      //O turn
	      else if(*turn == 'O')
		{
		  board[input[0]-96][input[1]-48] = 'O';
		}
	      return;
	    }
	  else
	    {
	      cout << "This spot is already taken! Please enter another one." << endl;
	    }
	}
      else
	{
	  cout << "Please enter letter + number. Ex. a1" << endl;
	}
    }
}

char checkWin(char board[4][4], char *turn)
{
  for(int i=1; i<4; i++)
    {
      //check rows
      if(board[i][1] == *turn && board[i][2] == *turn && board[i][3] == *turn)
	{
	  return *turn;
	}

      //check columns
      if(board[1][i] == *turn && board[2][i] == *turn && board[3][i] == *turn)
	{
	  return *turn;
	}
    }

  //check diagonals
  if(board[1][1] == *turn && board[2][2] == *turn && board[3][3] == *turn)
    {
      return *turn;
    }
  else if(board[1][3]==*turn && board[2][2]==*turn && board[3][1]==*turn)
    {
      return *turn;
    }
  return 'n';
}

void setBoard(char board[4][4])
{

  //initialize the board
  for(int i=0; i<4; i++)
    {
      board[0][i] = char(48+i);
      board[i][0] = char(96+i);
    }
  board[0][0] = ' ';
  
  for(int i=1; i<4; i++)
    {
      for(int j=1; j<4; j++)
	{
	  board[i][j] = ' ';
	}
    }
}

void printBoard(char board[4][4])
{
  for(int i=0; i<4; i++)
    {
      for(int j=0; j<4; j++)
	{
	  cout << board[i][j];
	}
      cout << endl;
    }
}
