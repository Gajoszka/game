#pragma once
#include "RoomElement.h"
#include "Player.h"
//class Player;

class Treasure : public RoomElement
{
public:
	Treasure() :RoomElement(3, static_cast<char>(158), true) {

	}
	GameAction conflict(Player* player) {
		(*player).addScore(2);
		return can_move;
	}
};

