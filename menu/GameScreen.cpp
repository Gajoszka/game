#include "GameScreen.h"
#include "KeyFunctions.h"
#include <iostream>
#include "Dungeon.h"



using namespace std;

GameScreen::GameScreen()
{
	KeyFunctions obj;
	cout << "User input" << endl;
	obj.movement();
}




