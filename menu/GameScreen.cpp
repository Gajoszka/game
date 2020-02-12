#include "GameScreen.h"
#include <iostream>
#include <conio.h>
#include "Screen.h"
#include "Dungeon.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_END 79

using namespace std;

GameScreen::GameScreen()
{
	gotoxy(x, y);
	cout << player << endl;
	cout << "User input" << endl;
	while (inp) {
		movement();
	}
}

void GameScreen::movement() {
	char move = _getch(); // keyboard response
	switch (move) {
	case KEY_UP:
		clear();
		y = y - 1;
		gotoxy(x, y);
		cout << player;
		break;
	case KEY_DOWN:
		clear();
		y = y + 1;
		gotoxy(x, y);
		cout << player;
		break;
	case KEY_LEFT:
		clear();
		x = x - 1;
		gotoxy(x, y);
		cout << player;
		break;
	case KEY_RIGHT:
		clear();
		x = x + 1;
		gotoxy(x, y);
		cout << player;
		break;
	case KEY_END:
		inp = false;
	}
}

void GameScreen::clear() {
	gotoxy(x, y);
	cout << " ";
}


