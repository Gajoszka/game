#pragma once
#include "RoomElement.h"
#include "GameType.h"

class Gun :
	public RoomElement
{
public:
	Gun(int range, int magazine) : RoomElement(id_gun, '.', false, -5) {
		this->magazine = magazine;
		this->range = range;
	};
	GameAction conflict(Player* player);
	bool canShot() {
		return magazine > 0;
	}

	void decrese() {
		magazine--;
	}

	int range = 4;
private:
	int magazine = 0;

};

