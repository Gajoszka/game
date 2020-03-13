#pragma once
#include "RoomElement.h"
#include "Player.h"
//class Player;

class Treasure : public RoomElement
{
public:
	Treasure() :RoomElement(3, static_cast<char>(158), true, 2) {

	}
	void conflict(Player* player) {
		(*player).addScore(score);
	}
};

