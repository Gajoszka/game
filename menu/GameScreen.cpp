#include "GameScreen.h"
#include <iostream>
#include <conio.h>
#include <conio.h>
#include "Screen.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_END 79

using namespace std;

GameScreen::GameScreen()
{
	int x = 10, y = 10;
	gotoxy(x, y);
	cout << player << endl;
	cout << "User input" << endl;
	bool inp = true;
	while (inp) {
		char move = _getch(); // keyboard response
		switch (move) {
		case KEY_UP:
			y = y - 1;
			gotoxy(x, y);
			cout << player;
			break;
		case KEY_DOWN:
			y = y + 1;
			gotoxy(x, y);
			cout << player;
			break;
		case KEY_LEFT:
			x = x - 1;
			gotoxy(x, y);
			cout << player;
			break;
		case KEY_RIGHT:
			x = x + 1;
			gotoxy(x, y);
			cout << player;
			break;
		case KEY_END:
			inp = false;
		}
	}
}
