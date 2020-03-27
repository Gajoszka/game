#include "Floor.h"
#include <windows.h>
#include "RoomMapBuilder.h"
/* Creating floor with multiplle rooms */
using namespace std;

// getting current room
Room* Floor::getRoom()
{
	return actRoom;
}

// room creation
void Floor::createRoom()
{
	roomNr++;
	elementFactory.clearEnemys();
	RoomMapBuilder roomBuilder(45, 15);
	//the higher score, the more obstacles
	roomBuilder.setScaleCount((rand() % min(abs(player->getScore()+ roomNr), 15)) + 1); // number of obstacles
	roomBuilder.setEnemyCount((rand() % min(abs(player->getScore())+ roomNr, 8)) + 1); // number of enemies
	roomBuilder.setDoorCount(1); // number of doors
	roomBuilder.setTreasureCount(rand() % 12); // number of treasure
	if (actRoom != nullptr)
		delete actRoom;
	actRoom = new Room(roomBuilder.build(),&elementFactory);
	(*actRoom).setPrinterMessage(bind(&GameLayout::print, layout, placeholders::_1, placeholders::_2));
	// mapping player and layout to current room
	(*player).setRoom(actRoom);
	(*layout).setRoom(actRoom);
}

// exit room and new room creation
void Floor::exitFromRoom()
{
	(*layout).printInfo("room change");
	Sleep(1000);
	createRoom();
	(*layout).printInfo("  ");
	Sleep(1000);
	(*layout).printInfo("");
}

GameAction Floor::runAction(GameAction action)
{
	action = (*player).runAction(action);
	switch (action)
	{
	case exitRoom:
		exitFromRoom();
		return served;;
	default:
		return (*actRoom).runAction(action);
	}
}

// destructor
Floor::~Floor()
{
	if (actRoom != nullptr)
		delete actRoom;
}