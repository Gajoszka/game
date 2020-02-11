#include "GameMain.h"
#include "GameScreen.h"
#include <stdio.h>
#include <stdlib.h>
//#include <curses.h>
#include <iostream>

using namespace std;

void GameMain::GameIntro()
{
	string name;
	cout << "Welcome to the game!" << endl;
	cout << "What's your name?" << endl;
	cin >> name;
	//store name to database
	system("CLS");
	GameScreen a;
	//starts displaying game mode
}
