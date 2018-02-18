#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <conio.h>
#include <iostream>
#include <fstream>

using namespace std;

const int MAP_HEIGHT = 16;
const int MAP_WIDTH = 33;


char inputKey;
//array var for drawing maps,replace later with file io
int mapArrayOne[16][33] =
{
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1 },
	{ 1,0,0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,1,0,1,1,0,1,0,0,1,0,0,1,1,1,1,0,0,1,0,0,1,0,0,1,1,1,1,0,0,1 },
	{ 1,0,0,1,0,1,0,0,1,0,0,0,0,0,1,0,0,1,0,0,1,0,0,0,0,0,1,0,0,1,0,0,1 },
	{ 1,0,0,1,0,1,1,1,1,1,1,1,1,1,1,0,0,1,0,0,1,1,1,1,1,1,1,0,0,1,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,0,0,1 },
	{ 1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1 },
	{ 1,0,0,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,1 }
};


//function prototypes
void drawMaze();
void setCursorXY(int x, int y);
void moveCharacter();


int main()
{
	drawMaze();
	moveCharacter();
	system("pause");
	return 0;
}


/* 
Draws maze to console 
*/
void drawMaze()
{
	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		for (int j = 0; j < MAP_WIDTH; j++)
		{
			switch (mapArrayOne[i][j])
			{
			case 0:
				cout << " ";
				break;
			case 1:
				cout << char(219); //square
				break;
			case 2:
				cout << " ";
				break;
			default:
				break;
			}
		}
		cout << " " << endl;
	}
}


/*Set position of cursor*/
void setCursorXY(int x, int y)
{
	COORD cursorPosition;
	cursorPosition.X = x;
	cursorPosition.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}

void moveCharacter()
{
	int x = 1;
	int y = 1;
	int xBefore = x;
	int yBefore = y;

	while (true)
	{
		//clear previous cursor position
		setCursorXY(xBefore, yBefore);
		cout << " ";

		setCursorXY(x, y);
		cout << char(1);

		xBefore = x;
		yBefore = y;

		//get character of keyboard input
		inputKey = _getch();

		//change cursor coordinates 
		switch (inputKey)
		{
		case 'w':
			y -= 1;
			break;
		case 'a':
			x -= 1;
			break;
		case 's':
			y += 1;
			break;
		case 'd':
			x += 1;
			break;
		default:
			break;
		}

		//check for collisions
		if (mapArrayOne[y][x] == 1)
		{
			x = xBefore;
			y = yBefore;
		}
	}
}