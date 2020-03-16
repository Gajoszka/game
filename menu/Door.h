#pragma once
#include "RoomElement.h"
#include "GameDef.h"
#include "Player.h"

class Door :public RoomElement
{
public:
	Door() :RoomElement(id_door, ' ', true,5) {

	}
	GameAction conflict(Creature* creature) {
		if (Player* player = dynamic_cast<Player*>(creature)) {
			player->addScore(score);
			return exitRoom;
		}return stop;
	}
};

