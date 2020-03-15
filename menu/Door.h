#pragma once
#include "RoomElement.h"
#include "GameDef.h"
#include "Player.h"

class Door :public RoomElement
{
public:
	Door() :RoomElement(id_door, ' ', true) {

	}
	GameAction conflict(Player* player) {
		(*player).addScore(5);
		return exitRoom;
	}
};

