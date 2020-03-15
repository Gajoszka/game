#include "Enemy.h"
#include "Player.h"
#include "Room.h"
#include "Screen.h"
#include "RoomElementFactory.h"

GameAction Enemy::conflict(Player* player)
{
	player->addScore(-15);
	moveDirection = changeDirection(moveDirection);
	player->boom();
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
			moveDirection = changeDirection(moveDirection);
		}
		i++;
	}
}

Point Enemy::changeDirection(Point direction) {
		int s = (rand() + 2) % 3 - 1; // choosing new direction, where the enemy can move
		direction.setColumn(s);
		direction.setRow(((direction.getRow() + 2 + s) % 3) - 1);
			if (0 == direction.getColumn() == direction.getRow())
				direction.setColumn(-1);
			return direction;
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
	if (Player* player = dynamic_cast<Player*>(actEl))
		conflict(player);
	else
		room->moveCreature(getLocation().getColumn() + columnStep, getLocation().getRow() + rowStep, 5, this);
	//setLocation(getLocation().getColumn() + columnStep, getLocation().getRow() + rowStep);
	return true;
}

void Enemy::shot() {
	if (!gun->canShot())
		return;
	Point  direction = changeDirection(moveDirection);
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
		if (Player* player = dynamic_cast<Player*>(actEl))
			gun->conflict(player);
		delay(50);
		(*room).printer(actColumn, actRow, (*actEl).icon); // to remove shots from previous postition
	}
}


