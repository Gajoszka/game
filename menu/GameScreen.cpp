#include "GameScreen.h"
#include "KeyFunctions.h"
#include "Player.h"
#include "InfoDisplay.h"
#include "Dungeon.h"
#include "Stats.h"
#include <iostream>

using namespace std;

GameScreen::GameScreen()
{
	//KeyFunctions obj;
	Dungeon go;
	Stats st;
	InfoDisplay info;
	Player user;
	go.test1();
	st.frame();
	info.infoFrame();
	user.playerSpace();
	//obj.movement();
}




