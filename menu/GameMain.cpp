#include "GameMain.h"
#include "GameScreen.h"
#include "DBconnection.h"
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <conio.h>
#include <iostream>

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
	/*Frame room(15, 45);
	game.setRoom(room);
	game.printScreen()*/;
	//starts displaying game mode
}
