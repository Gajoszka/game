#include "GameMain.h"
#include "GameScreen.h"
#include "DBconnection.h"
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <conio.h>
#include <iostream>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_END 79

using namespace std;

void GameMain::GameIntro()
{
	system("CLS");
	string name;
	cout << "Welcome to the game!" << endl;
	cout << "What's your name?" << endl;
	cin >> name;
	//store name, so it cann be added to database with a score
	system("CLS");
	GameScreen game;
}

void GameMain::movement() {
	int x=0;
	int y=0;
	while (inp) {
		x = 0;
		y = 0;
		char move = _getch(); // keyboard response
		switch (move) {
		case KEY_UP:
			y = -1;
			break;
		case KEY_DOWN:
			y = 1;
			break;
		case KEY_LEFT:
			x = -1;
			break;
		case KEY_RIGHT:
			x = 1;
			break;
		case KEY_END:
			inp = false;
		}
	}
};
