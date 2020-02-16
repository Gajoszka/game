#include "GameScreen.h"
#include "KeyFunctions.h"
#include "Dungeon.h"
#include <iostream>

using namespace std;

GameScreen::GameScreen()
{
	KeyFunctions obj;
	Dungeon go;
	cout << "User input" << endl;
	go.test1();
	obj.movement();
}




