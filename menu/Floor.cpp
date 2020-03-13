#include "Floor.h"
#include "RoomBuilder.h"
#include <windows.h>
using namespace std;

Room* Floor::getRoom()
{
	return &actRoom;
}

void Floor::createRoom()
{
	roomNr++;
	RoomBuilder roomBuilder(45, 15);
	//the higher score, the more obstacles
	roomBuilder.setScaleCount((rand() % min(max(8, roomNr), 15)) + 1);
	roomBuilder.setEnemyCount((rand() % min(max(3, roomNr), 10)) + 1);
	roomBuilder.setDoorCount(1);
	roomBuilder.setTreasureCount(rand() % 12);
	actRoom = roomBuilder.build();
	actRoom.setPrinterMessage(bind(&GameLayout::print, layout, placeholders::_1, placeholders::_2));

	(*player).setRoom(&actRoom);
	(*layout).setRoom(&actRoom);
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
		return action;
	}
}

