#pragma once
/* Child class inheriting from Creature class
*/
#include "Creature.h"

class Enemy : public Creature
{
public:
	// enemy extends creature with its unique data
	Enemy(int id) : Creature(id,'E', 2, 1, 1) {
		//this->room = room;
	};
	void run() {

	}
private:

};

