#include "Enemy.h"
#include "Player.h"
#include "Room.h"
#include "Screen.h"
#include "RoomElementFactory.h"
/* Controlling enemy movement and loation*/

// death when encounter player
GameAction Enemy::conflict(Creature* creature)
{
	if (Player* player = dynamic_cast<Player*>(creature)) {
		death(); 
		return player->decreseLives();
	}
	return served;
}

// enemy explodes when dying
void Enemy::death()
{
	pRoom->boomSimulation(this, true);
}

// destructor
Enemy::~Enemy()
{
	delete pGun;
}

// enemy inside room and moves inside room
void Enemy::setRoom(Room* room)
{
	this->pRoom = room;
	pGun = room->getElementFactory()->getGun();
}

//enemy movement
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

// changing direction if obstacle encountered
Point Enemy::changeDirection(Point direction) {
	int s = (direction.getColumn() + 2) % 3 - 1; // choosing new direction, where the enemy can move
	direction.setColumn(s);
	direction.setRow(((direction.getRow() + 2 + s) % 3) - 1);
	if (0 == direction.getColumn() && 0 == direction.getRow())
		direction.setColumn(-1);
	return direction;
}

// checking if enemy can move in current direction
RoomElement* Enemy::canMove(int column, int row) {
	if (pRoom->canMove(column, row, this))
		return pRoom->get(column, row);
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
		pRoom->moveSimulation(getLocation().getColumn() + columnStep, getLocation().getRow() + rowStep, 5, this);
	return served;
}

GameAction Enemy::shot() {
	return pGun->shot(pRoom, this);
}


