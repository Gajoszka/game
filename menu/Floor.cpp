#include "Floor.h"
#include "RoomBuilder.h"
#include <windows.h>
#include "RoomMapBuilder.h"
using namespace std;

Room* Floor::getRoom()
{
	return actRoom;
}

void Floor::createRoom()
{
	roomNr++;
	elementFactory.clearEnemys();
	RoomMapBuilder roomBuilder(45, 15);
	//the higher score, the more obstacles
	roomBuilder.setScaleCount((rand() % min(max((*player).getScore(), roomNr), 15)) + 1);
	roomBuilder.setEnemyCount((rand() % min(max((*player).getScore(), roomNr), 10)) + 1);
	roomBuilder.setDoorCount(1);
	roomBuilder.setTreasureCount(rand() % 12);
	if (actRoom != nullptr)
		delete actRoom;
	actRoom = new Room(roomBuilder.build(),&elementFactory);
	(*actRoom).setPrinterMessage(bind(&GameLayout::print, layout, placeholders::_1, placeholders::_2));

	(*player).setRoom(actRoom);
	(*layout).setRoom(actRoom);
}

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

Floor::~Floor()
{
	if (actRoom != nullptr)
		delete actRoom;
}


