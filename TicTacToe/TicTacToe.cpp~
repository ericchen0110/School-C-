#include <iostream>

using namespace std;

void drawBoard(char (&board)[][4]);

int main()
{
  char board[4][4];

  //draw the board
  drawBoard(&board);

  return 0;
}

void drawBoard(char (&board)[][4])
{

  //initialize the board
  for(int i=0; i<4; i++)
    {
      *board[0][i] = char(i);
      *board[i][0] = char(97+i);
    }
  *board[0][0] = ' ';
  
  for(int i=1; i<4; i++)
    {
      for(int j=1; j<4; j++)
	{
	  *board[i][j] = ' ';
	}
    }


  //print board
  for(int i=0; i<4; i++)
    {
      for(int j=0; j<4; j++)
	{
	  cout << *board[i][j];
	}
      cout << endl;
    }
}
