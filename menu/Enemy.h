#pragma once
using namespace std;

/* Child class inheriting from Creature class
*/
#include "Creature.h"

class Enemy : public Creature
{
public:
	// enemy extends creature with its unique data
	Enemy(int id) : Creature(id,'E', 2, 1, 1), moveDirection( 1,0){
		//this->room = room;
	};
	void run() {

	}
	void setMoveDirection(int column, int row) {
		moveDirection.setColumn(column);
		if (0 == column == row)
			row = -1;
		moveDirection.setRow(row);
	}

	Point getMoveDirection() {
		return moveDirection;
	}
private:
	Point moveDirection;
};

