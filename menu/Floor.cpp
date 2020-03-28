#include "Floor.h"
#include <windows.h>
#include "RoomMapBuilder.h"
/* Creating floor with multiplle rooms */
using namespace std;

// getting current room
Room* Floor::getRoom()
{
	return pActRoom;
}

// room creation
void Floor::createRoom()
{
	roomNr++;
	elementFactory.clearEnemys();
	RoomMapBuilder roomBuilder(45, 15);
	//the higher score, the more obstacles
	roomBuilder.setScaleCount((rand() % min(abs(pPlayer->getScore()+ roomNr), 15)) + 1); // number of obstacles
	roomBuilder.setEnemyCount((rand() % min(abs(pPlayer->getScore())+ roomNr, 8)) + 1); // number of enemies
	roomBuilder.setDoorCount(1); // number of doors
	roomBuilder.setTreasureCount(rand() % 12); // number of treasure
	if (pActRoom != nullptr)
		delete pActRoom;
	pActRoom = new Room(roomBuilder.build(),&elementFactory);
	pActRoom->setPrinterMessage(bind(&GameLayout::print, pLayout, placeholders::_1, placeholders::_2));
	// mapping player and layout to current room
	pPlayer->setRoom(pActRoom);
	pLayout->setRoom(pActRoom);
}

// exit room and new room creation
void Floor::exitFromRoom()
{
	pLayout->printInfo("room change");
	Sleep(1000);
	createRoom();
	pLayout->printInfo("  ");
	Sleep(1000);
	pLayout->printInfo("");
}

GameAction Floor::runAction(GameAction action)
{
	action = pPlayer->runAction(action);
	switch (action)
	{
	case exitRoom:
		exitFromRoom();
		return served;;
	default:
		return pActRoom->runAction(action);
	}
}

// destructor
Floor::~Floor()
{
	if (pActRoom != nullptr)
		delete pActRoom;
}