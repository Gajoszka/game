#include "GameScreen.h"
#include "Frame.h"
#include "KeyFunctions.h"
#include "Player.h"
#include "InfoDisplay.h"
#include "Dungeon.h"
#include "Stats.h"
#include <iostream>

using namespace std;

GameScreen::GameScreen() {
	/*frame main(70, 40);
	main.printframe(1, 1);
	frame room(45, 15);
	room.printframe(2, 2);
	frame stats(20, 15);
	stats.printframe(47,2);
	frame info(45, 5);
	info.printframe(2, 17);*/
	KeyFunctions obj;
	Dungeon go;
	Stats st;
	InfoDisplay info;
	//Player user;
	go.test1();
	st.frame();
	info.infoFrame();
	//user.playerSpace();
	obj.movement();
};


//void GameScreen::setRoom(Frame room) {
//	this->actualRoom = room;
//};
//
//void GameScreen::printScreen() {
//	this->actualRoom.printFrame(10, 10);
//};


