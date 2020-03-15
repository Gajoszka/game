#include "Enemy.h"
#include "Player.h"
#include "Room.h"

GameAction Enemy::conflict(Player* player)
{
	player->addScore(-10);
	return can_move;
}

void Enemy::setRoom(Room* room)
{
	this->room = room;

}


void Enemy::move() {
	Point actLocation = getLocation();
	int i = 0;
	bool ok = false;
	while (i < 10 && !ok) { // i < 10 so the loop is not infinite
		// first in current direction, if impossible - change
		if (!(ok = move(moveDirection.getColumn(),moveDirection.getRow()))) {
			int s = (moveDirection.getColumn() + 2) % 3 - 1; // choosing new direction, where the enemy can move
			moveDirection.setColumn(s);
			moveDirection.setRow(((moveDirection.getRow() + 2 + s) % 3) - 1);
			if (0 == moveDirection.getColumn() == moveDirection.getRow())
				moveDirection.setColumn(-1);
		}
		i++;
	}
}


//manual setup
bool Enemy::move(int columnStep, int rowStep) {
	RoomElement* actEl = (*room).get(getLocation().getColumn() + columnStep, getLocation().getRow() + rowStep);
	if (actEl==nullptr
		|| (0 == columnStep && 0 == rowStep) 
		|| !(*actEl).canPass 
		|| (*actEl).id == id_door 
		|| (*actEl).id == id_treasure
		|| (*actEl).id >= 1000)
		return false;
	(*room).moveCreature(getLocation().getColumn() + columnStep, getLocation().getRow() + rowStep,10, this);
	//setLocation(getLocation().getColumn() + columnStep, getLocation().getRow() + rowStep);
	return true;
}

