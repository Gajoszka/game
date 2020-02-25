#pragma once
#include "Creature.h"
//#include "Room.h"

class Enemy : public Creature
{
public:
	Enemy(int id) : Creature(id,'E', 2, 1, 1) {
		//this->room = room;
	};
	void run() {

	}
private:
	//Room *room;
};

