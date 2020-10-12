/*
Jordan Ganaway
00072628
jganaway@their.athens.edu

****SOURCES CITED****
Base code by Katia Maxwell

Try-catch statements:
https://docs.microsoft.com/en-us/cpp/cpp/try-throw-and-catch-statements-cpp?view=vs-2019

stoi:
https://www.geeksforgeeks.org/converting-strings-numbers-cc/
*/
#include <iostream>
#include <iomanip>
#include <string>
#include <time.h>   // For time()
#include <cstdlib>  // For srand() and rand()
using namespace std;
const int ROWS = 8;
const int COLS = 8;
char waterBoard[ROWS][COLS];
char intlWaters[ROWS][COLS];
int AHP = 0; //carrier
int BHP = 0; //battleship
int CHP = 0; //cruiser
int aStat = 0;
int bStat = 0;
int cStat = 0;

void emptyWaters()
{
	for(int i = 0; i < ROWS; i++)
	{
		for(int j = 0; j < COLS; j++)
		{
			waterBoard[i][j] = '~';
			cout<<waterBoard[i][j] << "\t";
		}
		cout << endl;
	}
}

void Display(char intlWaters[ROWS][COLS])
{
	for(int i = 0; i < ROWS; i++)
	{
		for(int j = 0; j < COLS; j++)
		{
			cout<<intlWaters[i][j] << "\t";
		}
		cout << endl;
	}
}

void placementCarrier()
{
	char acarrier='A';
	bool validrow = false;
	bool validcolumn = false;
	srand(time(NULL));
	int position;
	char c;
	position=rand()%2;
	if(position == 1)
		c = 'h';
	else
		c = 'v';
	int row;
	int column;
	row = rand()%7;
	column = rand()%7;
		while(validrow == false)
		{	
			if(row + 4 > 7)
			{
				validrow = false;
				row = rand()%7;
			}
			else
      validrow = true;
			cout << validrow;
    }
		while(validcolumn == false)
		{
			if(column + 4 > 7)
			{
				validcolumn = false;
				column = rand()%7;
			}
			else
			validcolumn = true;
			cout << validcolumn;
		}
	if(c == 'h')
	{
		waterBoard[row][column] = 'A';
		waterBoard[row+1][column] = 'A';
		waterBoard[row+2][column] = 'A';
		waterBoard[row+3][column] = 'A';
		waterBoard[row+4][column] = 'A';
	}
	else
	{	
		waterBoard[row][column] = 'A';
		waterBoard[row][column+1] = 'A';
		waterBoard[row][column+2] = 'A';
		waterBoard[row][column+3] = 'A';
		waterBoard[row][column+4] = 'A';
	}
}

void placementBattleship()
{
	char battleship = 'B';
	bool validrow = false;
	bool validcolumn = false;
	srand(time(NULL));
	int position;
	char c;
	position = rand()%2;
	if(position == 1)
		c = 'h';
	else
		c = 'v';
	int row;
	int column;
		row = rand()%7;
		column = rand()%7;
			while(validrow == false)
			{	
				if(row + 4 > 7)
				{
					validrow = false;
					row = rand()%7;
				}
				else
					validrow = true;
				
				cout << validrow;
			}
			while(validcolumn == false)
			{
				if(column + 4 > 7)
				{
					validcolumn = false;
					column = rand()%7;
				}
				else
					validcolumn = true;
			 cout << validcolumn;
			}
		if(c == 'h')
		{
			if(waterBoard[row][column] != '~' || waterBoard[row+1][column] != '~' || waterBoard[row+2][column] != '~' ||waterBoard[row+3][column] != '~')
			{
				placementBattleship();
			}
			else
			{
				waterBoard[row][column] = 'B';
				waterBoard[row+1][column] = 'B';
				waterBoard[row+2][column] = 'B';
				waterBoard[row+3][column] = 'B';
			}
		}
		else
		{	
			if(waterBoard[row][column] != '~' || waterBoard[row][column+1] != '~' || waterBoard[row][column+2] != '~' ||waterBoard[row][column+3] != '~')
			{
				placementBattleship();
			}
			else	
			{
				waterBoard[row][column] = 'B';
				waterBoard[row][column+1] = 'B';
				waterBoard[row][column+2] = 'B';
				waterBoard[row][column+3] = 'B';
			}
		}
}

void placementCruiser()
{
	char battleship = 'C';
	bool validrow = false;
	bool validcolumn = false;
	srand(time(NULL));
	int position;
	char c;
	position=rand()%2;
	if(position == 1)
		c = 'h';
	else
		c = 'v';
	int row;
	int column;
		row = rand()%7;
		column = rand()%7;
			while(validrow == false)
			{	
				if(row + 4 > 7)
				{
					validrow = false;
					row = rand()%7;
				}
				else
					validrow = true;
				
				cout << validrow;
			}
			while(validcolumn == false)
			{
				if(column + 4 > 7)
				{
					validcolumn = false;
					column = rand()%7;
				}
				else
				validcolumn = true;
				cout << validcolumn;
			}
		if(c == 'h')
		{
			if(waterBoard[row][column] != '~' || waterBoard[row+1][column] != '~' || waterBoard[row+2][column] != '~' )
			{
				placementCruiser();		
			}
			else
			{
				waterBoard[row][column] = 'C';
				waterBoard[row+1][column] = 'C';
				waterBoard[row+2][column] = 'C';
			}
		}
		else
		{	
			if(waterBoard[row][column] != '~' || waterBoard[row][column+1] != '~' || waterBoard[row][column+2] != '~')
			{
				placementCruiser();
			}
			else	
			{
				waterBoard[row][column] = 'C';
				waterBoard[row][column+1] = 'C';
				waterBoard[row][column+2] = 'C';		
			}
		}
}

bool gridValidation(int rowPoint, int colPoint)
{
  /*
  WRITE A FUNCTION TO VALIDATE THAT THE SELECTION THE USER HAS MADE IS WITHIN THE GRID OF THE OCEAN 8X8 (COUNT STARTS AT 0)
  -Verify that the place that the user is trying to bomb is valid. A valid spot is considered one that if found within the 2D array.
  */
  bool result = false;
  if (rowPoint >= 0 && rowPoint <= 7 )
  {
    if(colPoint <= 7 && colPoint >= 0)
    {
      result = true;
    }
    else
    {
      result = false;
    }
  }
  return result;
}

int hitCheck(string rowPoint, string colPoint)
{
  /*
  WRITE A FUNCTION TO CHECK IF THE USER HAS HIT A SHIP OR WATER; DO NOT ALLOW THE USER TO SELECT TO "BOMB" A SPOT THAT HE/SHE HAS ALREADY BOMBED.	ALLOW THE USER TO ENTER 'Q' IF HE OR SHE WANTS TO QUIT THE GAME.
  -Check if the user has hit a ship or water. If the user hits a ship place a B in that spot. If the user hits water place an M in that spot.
  -Verify that the place the user is trying to bomb is not one that he or she has already hit or missed.
  -If the user chooses to quit (use ‘Q’ for quitting) then the game board should be displayed.
  */
  int rowInt;
  int colInt;
  bool result;

  if(rowPoint == "Q"||rowPoint == "q" || colPoint == "Q"||colPoint == "q")
  {
    return 4; 
  }
  
  rowInt = stoi(rowPoint);
  colInt = stoi(colPoint);
  result = gridValidation(rowInt, colInt);

  if(result == false)
  {
    cout<<"Invalid Coordinates, Captain. Please enter a number between 0 and 7."<<endl;
    return 5;
  }
if(intlWaters[rowInt][colInt] == '~')
{
  if(waterBoard[rowInt][colInt] == 'A')
  {
    intlWaters[rowInt][colInt] = 'B';
    AHP++;
  }
  else if(waterBoard[rowInt][colInt] == 'B')
  {
    intlWaters[rowInt][colInt] = 'B';
    BHP++;
  }
  else if(waterBoard[rowInt][colInt] == 'C')
  {
    intlWaters[rowInt][colInt] = 'B';
    CHP++;
  }
  else
  {
    intlWaters[rowInt][colInt] = 'M';
  }
}
else
{
  cout<<"You already bombed there, Captain!"<<endl;
}
  return 1;
}

void sunkCheck()
{
  /*
  WRITE A FUNCTION TO CHECK IF A SHIP HAS BEEN SUNK (5 HITS FOR CARRIER, 4 HITS FOR BATTLESHIP, 3 HITS FOR CRUISER): INFORM USER WHEN A SHIP HAS SUNK AND WHICH SHIP IT WAS
  -Write a function to check if a ship has been sunk, and if so which ship.
  */
  if(AHP >= 5)
  {
    cout << "You sunk their Carrier, Captain!" << endl;
    aStat = 1;
  }
  if(BHP >= 4)
  {
    cout << "You sunk their Battleship, Captain!" << endl;
    bStat = 1;
  }
  if(CHP >= 3)
  {
    cout << "You sunk their Cruiser, Captain!" << endl;
    cStat = 1;
  }
}

char winCheck()
{
  /*
  WRITE A FUNCTION THAT DETERMINES IF THE USER HAS WON THE GAME
    IMPORTANT NOTE: THE DISPLAY FUNCTION WILL SHOW WHERE THE SHIPS ARE HIDDEN, DO NOT SHOW THIS TO YOUR USER DURING "OFFICIAL" GAME PLAY (THIS WILL BE THE SCREEN SHOT YOU SUBMIT WITH YOUR CODE) YOU MAY USE THE DISPLAY FUNCTION WHILE WRITING AND TESTING OUR YOU PROGRAM. BUT REMEMBER TO ONLY SHOW IT TO THE USER AT THE END, EITHER BECAUSE THE USER HAS QUIT, OR HAS WON THE GAME
  -Finally write a function that determines if the user has won the game
  -If the user wins the game, display the final game board.
  */
  if (aStat == 1 && bStat == 1 && cStat == 1)
  {
    cout << "Congratulations, you win!"<<endl;
    return 'Q';
  }
  return 'C';
}

char bombChoice()
{
  string rowPoint = "Q";
  string colPoint = "Q";
  int result;
  cout<<"Enter 'Q' to quit at any point, Captain."<<endl;
  cout<<"Please Enter a Row Coordinate between 0 and 7, Captain."<<endl;
while(true)
  {
    try
    {
      cin>>rowPoint;
      if((rowPoint == "Q" || rowPoint == "q"))
      {
        break;
      }
      else if(stoi(rowPoint) <= 0 || stoi(rowPoint) > 0)
      {
        break;
      }
        cout<<"Invalid Input"<<endl;
    }

    catch(const exception& e)
    {
      cout<<"Not a number, please enter a number."<<endl;
    }
  }
  if(rowPoint == "Q"||rowPoint == "q")
  {
    result = hitCheck(rowPoint, colPoint);
    return 'Q';
  }
  cout<<"Please Enter a Column Coordinate between 0 and 7, Captain."<<endl;
  
  while(true)
  {
    try
    {
      cin>>colPoint;
      if((colPoint == "Q" || colPoint == "q"))
      {
        break;
      }
      else if(stoi(colPoint) <= 0 || stoi(colPoint) > 0)
      {
        break;
      }
        cout<<"Invalid Input"<<endl;
    }

    catch(const exception& e2)
    {
      cout<<"Not a number, please enter a number between 0 and 7, Captain."<<endl;
    }
  }

  if(colPoint == "Q"||colPoint == "q")
  {
    
    result = hitCheck(rowPoint, colPoint);
    return 'Q';
  }
  result = hitCheck(rowPoint, colPoint);

  return 'G';
}

void myWaters(char intlWaters[ROWS][COLS])
{
  for(int i = 0; i < ROWS; i++)
	{
		for(int j = 0; j < COLS; j++)
		{
			intlWaters[i][j] = '~';
			cout<<intlWaters[i][j] << "\t";
		}
	}
}

int main()
{
  char quitQuery = 'G';
  myWaters(intlWaters);
//DO NOT CHANGE THE FUNCTION CALLS BELOW, THIS SETS UP THE GAME!
	emptyWaters();
	placementCarrier();
	placementBattleship();
	placementCruiser();
  cout<<endl;
	//START YOUR MAIN FUNCTION CODE BELOW...
	//THE CODE THAT YOU PROVIDE SHOULD BE ASSOCITED TO FUNCTION CALLS TO THE FUNCTIONS THAT YOU HAVE, WRITTEN ALONG WITH ANY OTHER CODE TO CREATE THIS "GAME PLAY". THE GAME IS BATTLESHIP BUT ONLY WITH 3 SHIPS.
  while(quitQuery != 'Q')
  {
    Display(intlWaters);
    quitQuery = bombChoice();
    if(quitQuery == 'Q' || quitQuery == 'q')
    {
      break;
    }
    sunkCheck();
    quitQuery = winCheck();
  }
	return 0;
}