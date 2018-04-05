#include "iostream"
#include "conio.h"
#include "windows.h"
#include "fstream"

using namespace std;
bool gameover;
const int width = 30;
const int height = 20;
int x, y, foodX, foodY, score;
enum movement { STOP, LEFT, RIGHT, UP, DOWN };
movement moove;
int tailX[100], tailY[100], nTail; 

void Beginning()
{
	gameover = false;
	moove = STOP;
	x = width / 2;
	y = height / 2;
	foodX = rand() % width;
	foodY = rand() % height;
	score = 0;
}

void Draw()
{
	system("cls");
	for (int i = -1; i <= height; i++)
	{
		for (int j = -1; j <= width; j++)
		{
			if (i == -1 || i == height || j == -1 || j == width)
				cout << "T";
			else if (i == y && j == x)
				cout << "0";
			else if (i == foodY && j == foodX)
				cout << "F";
			else
			{
				bool print = false;
				for (int k = 0; k < nTail; k++)
				{
					if (tailX[k] == j && tailY[k] == i) 
					{
						print = true;
						cout << "o";
					}
				}
				if (!print)
					cout << " ";
			}
		}
		cout << endl;
	}
	cout << endl << "Score: " << score << endl;
}

void Keys() {
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			moove = LEFT;
			break;
		case 'd':
			moove = RIGHT;
			break;
		case 's':
			moove = DOWN;
			break;
		case 'w':
			moove = UP;
			break;
		case 'x':
			gameover = true;
			break;
		}
	}
}

void Game()
{
	Sleep(100);
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = x;
	tailY[0] = y;
	for (int i = 1; i < nTail; i++)
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}
	switch (moove)
	{
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	}
	if (x >= width)
		x = 0;
	else if (x < 0)
		x = width - 1;
	if (y >= height)
		y = 0;
	else if (y < 0)
		y = height - 1;
	for (int i = 0; i < nTail; i++)
	{
		if (tailX[i] == x && tailY[i] == y)
			gameover = true;
	}
	if (x == foodX && y == foodY)
	{
		score = score + 10;
		foodX = rand() % width;
		foodY = rand() % height;
		nTail++;
	}
}

int main()
{
	char *name = new char[255];
	cout << " Enter your name: ";
	cin >> name;
	Beginning();
	while (!gameover)
	{
		Draw();
		Keys();
		Game();
	}
	ofstream writer;
	writer.open("Results.txt", ios::out | ios::app);
	writer << name << " - " << score << endl;
	writer.close();
	return 0;
}