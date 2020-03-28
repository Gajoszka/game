#include "Player.h"
#include <iostream>
#include <string>
#include "Screen.h"
#include "Room.h"
#include "Enemy.h"
#include "Weapon.h"
/*Defining players and their attributes and abilities*/
using namespace std;

void Player::addScore(int s) {
	if (s < 0)
		pRoom->boomSimulation(this, false);
	score = score + s;
	printerMsg(messageType::score, to_string(score));
}
int Player::getScore() {
	return score;
}
string Player::getName() {
	return name;
}

void Player::setRoom(Room* room)
{
	this->pRoom = room;
	room->putInInner(this);
	if (pGun == nullptr)
		pGun = new Gun();
	refreshInfo();
}

void Player::refreshInfo() {
	printerMsg(messageType::score, to_string(score));
	printerMsg(messageType::lives, to_string(lives));
	printerMsg(messageType::ammunition, to_string(pGun->getAmmunition()));
}

Player::~Player()
{
	if (pGun != nullptr)
		delete pGun;
}

// player movement
GameAction Player::move(int columnStep, int rowStep) {
	RoomElement* nextEl = pRoom->get(getLocation().getColumn() + columnStep, getLocation().getRow() + rowStep);
	GameAction action = nextEl->conflict(this);
	if (action == can_move || action == exitRoom) { // checking whether player can move in chosen direction
		lastMoveDirection.setColumn(columnStep);
		lastMoveDirection.setRow(rowStep);
		GameAction action1 = pRoom->moveSimulation(getLocation().getColumn() + columnStep, getLocation().getRow() + rowStep, 20, this);
		if (action != exitRoom)
			return action1;
	}
	return action;
}

// shooting and changing amunition amount
GameAction Player::shot() {
	pGun->shot(pRoom, this);
	pRoom->printerMsg(messageType::ammunition, to_string(pGun->getAmmunition()));
	return served;
}


GameAction Player::runAction(GameAction action)
{
	switch (action)
	{
	case served:
		return action;
	case key_up:
		return move(0, -1);
	case key_down:
		return move(0, 1);
	case key_left:
		return move(-1, 0);
	case key_right:
		return move(1, 0);
	case fire:
		return shot();
	case buy_ammunition:
		if (score > 10) {
			score -= 10;
			pGun->addAmmunition(5);
			printerMsg(messageType::score, to_string(score));
			printerMsg(messageType::ammunition, to_string(pGun->getAmmunition()));
			printerMsg(messageType::info_delay, "Bought ammunition");
			return served;
		}
		else
			printerMsg(messageType::info_delay, "not enough");
	default:
		return action;
	}
}