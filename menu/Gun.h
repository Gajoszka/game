#pragma once
#include "RoomElement.h"
#include "GameType.h"
#include "Creature.h"

class Gun :	public RoomElement {
public:
	Gun(int range, int magazine) : RoomElement(id_gun_min, '.', false, -5) {
		this->ammunition = magazine;
		this->range = range;
	};
	GameAction conflict(Creature* creature);
	GameAction shot(Room* room, Creature* shooter);
	bool canShot() {
		return ammunition > 0;
	}
	int getAmmunition() {
		return ammunition;
	}

	void addAmmunition(int add) {
		ammunition += add;
	}
	
protected:
	int range = 4;
	int ammunition = 0;
private:
	

};

