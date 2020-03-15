#include "Enemy.h"
#include "Player.h"
#include "Room.h"
#include "Screen.h"
#include "RoomElementFactory.h"

GameAction Enemy::conflict(Player* player)
{
	player->addScore(-15);
	return can_move;
}

Enemy::~Enemy()
{
	delete gun;
}

void Enemy::setRoom(Room* room)
{
	this->room = room;
	gun = room->getElementFactory()->getGun(6, 50);
}

void Enemy::move() {
	Point actLocation = getLocation();
	int i = 0;
	bool ok = false;
	while (i < 10 && !ok) { // i < 10 so the loop is not infinite
		// first in current direction, if impossible - change
		if (!(ok = move(moveDirection.getColumn(), moveDirection.getRow()))) {
			int s = (moveDirection.getColumn() + 2) % 3 - 1; // choosing new direction, where the enemy can move
			moveDirection.setColumn(s);
			moveDirection.setRow(((moveDirection.getRow() + 2 + s) % 3) - 1);
			if (0 == moveDirection.getColumn() == moveDirection.getRow())
				moveDirection.setColumn(-1);
		}
		i++;
	}
}

RoomElement* Enemy::canMove(int column, int row) {
	RoomElement* actEl = room->get(column, row);
	if (actEl == nullptr
		|| !actEl->canPass
		|| actEl->id == id_door
		|| actEl->id == id_treasure
		|| actEl->id >= 1000)
		return nullptr;
	return actEl;
}

//manual setup
bool Enemy::move(int columnStep, int rowStep) {
	RoomElement* actEl = canMove(getLocation().getColumn() + columnStep, getLocation().getRow() + rowStep);
	if (actEl == nullptr)
		return false;
	room->moveCreature(getLocation().getColumn() + columnStep, getLocation().getRow() + rowStep, 5, this);
	//setLocation(getLocation().getColumn() + columnStep, getLocation().getRow() + rowStep);
	return true;
}

void Enemy::shot() {
	if (!gun->canShot())
		return;
	Point  direction = moveDirection;
	int s = (rand()) % 3 - 1; // choosing new direction, where the enemy can move
	direction.setColumn(s);
	direction.setRow(((moveDirection.getRow() + 2 + s) % 3) - 1);
	int actColumn = getLocation().getColumn();
	int actRow = getLocation().getRow();
	RoomElement* actEl;
	for (int i = 1; i < gun->range; i++) {
		actColumn = actColumn + direction.getColumn(); // shoots in moving direction
		actRow = actRow + direction.getRow();
		actEl = canMove(actColumn, actRow);
		// if enemy can no longer move forward, escape
		if (actEl == nullptr)
			return;

		room->printer(actColumn, actRow, gun->icon);
		if (instanceof<Player>(actEl))
			gun->conflict((Player*)actEl);
		delay(50);
		(*room).printer(actColumn, actRow, (*actEl).icon); // to remove shots from previous postition
	}
}


