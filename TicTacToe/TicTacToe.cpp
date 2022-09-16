#include <iostream>
#include <string>

using namespace std;

void createBoard(char board[4][4]);
void printBoard(char board[4][4]);
void play(char board[4][4], int *turn);

int main()
{
  //first bracket is letter, second is num
  char board[4][4];
  
  //check turns, X=0, O=1;
  int turn = 0;

  //create the board
  createBoard(board);

  //print the board
  printBoard(board);

  //user play
  play(board, &turn);

  return 0;
}

void play(char board[4][4], int *turn)
{
  char input[3];
  if(isalpha(input[0]) && isdigit(input[1]))
    {
      //X turn
      if(*turn == 0)
	{
	  //get input
	  cout << "X turn" << endl << "Enter your command. (ex. a1)" << endl;
	  cin.getline(input, 3);
	  board[input[0]][input[1]] = 'X';
	}
      //O turn
      else if(*turn == 1)
	{
	  cout << "O turn" << endl << "Enter your command. (ex. a1)" << endl;
	  cin.getline(input, 3);
	  board[input[0]][input[1]] = 'O';
	}
      return;
    }
  //check exceptions
  else
    {
      cout << "The format is letter + number, ex. a1." << endl;
      play(board, turn);
    }
}

void createBoard(char board[4][4])
{
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
  cout << endl;
}
