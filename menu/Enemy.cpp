#include "Enemy.h"
#include "Player.h"
#include "Room.h"
#include "Screen.h"
#include "RoomElementFactory.h"

GameAction Enemy::conflict(Creature* creature)
{
	if (Player* player = dynamic_cast<Player*>(creature)) {
		death(); 
		return player->decreseLives();
	}
	//lastMoveDirection = changeDirection(lastMoveDirection);
	return served;
}

void Enemy::death()
{
	room->boomSimulation(this, true);
}

Enemy::~Enemy()
{
	delete gun;
}

void Enemy::setRoom(Room* room)
{
	this->room = room;
	gun = room->getElementFactory()->getGun(6, 40);
}

GameAction Enemy::move() {
	Point actLocation = getLocation();
	int i = 0;
	GameAction action =none ;
	while (i < 10 && action ==none) { // i < 10 so the loop is not infinite
		// first in current direction, if impossible - change
		if (none==(action = move(lastMoveDirection.getColumn(), lastMoveDirection.getRow()))) {
			lastMoveDirection = changeDirection(lastMoveDirection);
		}
		i++;
	}
	return action==none? served:action;
}

Point Enemy::changeDirection(Point direction) {
	int s = (direction.getColumn() + 2) % 3 - 1; // choosing new direction, where the enemy can move
	direction.setColumn(s);
	direction.setRow(((direction.getRow() + 2 + s) % 3) - 1);
	if (0 == direction.getColumn() && 0 == direction.getRow())
		direction.setColumn(-1);
	return direction;
}

RoomElement* Enemy::canMove(int column, int row) {
	if (room->canMove(column, row, this))
		return room->get(column, row);
	return nullptr;
}

//manual setup
GameAction Enemy::move(int columnStep, int rowStep) {
	RoomElement* actEl = canMove(getLocation().getColumn() + columnStep, getLocation().getRow() + rowStep);
	if (actEl == nullptr)
		return none;
	if (Player* player = dynamic_cast<Player*>(actEl))
		return conflict(player);
	else
		room->moveSimulation(getLocation().getColumn() + columnStep, getLocation().getRow() + rowStep, 5, this);
	//setLocation(getLocation().getColumn() + columnStep, getLocation().getRow() + rowStep);
	return served;
}

GameAction Enemy::shot() {
	return gun->shot(room, this);
}


