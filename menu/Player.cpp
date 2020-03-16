#include "Player.h"
#include <iostream>
#include <string>
#include "Screen.h"
#include "Room.h"
#include "Enemy.h"

using namespace std;

void Player::addScore(int s) {
	if (s < 0)
		boom();
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
	this->room = room;
	room->putInInner(this);
	printerMsg(messageType::score, to_string(score));
	printerMsg(messageType::ammunition, to_string(gun->getAmmunition()));
}

void Player::boom()
{
	room->boomSimulation(this, false);
}

Player::~Player()
{
	if (gun != nullptr)
		delete gun;
}

GameAction Player::move(int columnStep, int rowStep) {
	RoomElement* nextEl = room->get(getLocation().getColumn() + columnStep, getLocation().getRow() + rowStep);
	GameAction action = nextEl->conflict(this);
	if (action == can_move || action == exitRoom) {
		lastMoveDirection.setColumn(columnStep);
		lastMoveDirection.setRow(rowStep);
		GameAction action1 = room->moveCreature(getLocation().getColumn() + columnStep, getLocation().getRow() + rowStep, 20, this);
		if (action != exitRoom)
			return action1;
	}
	return action;
}

GameAction Player::shot() {
	gun->shot(room, this);
	room->printerMsg(messageType::ammunition, to_string(gun->getAmmunition()));
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
			gun->addAmmunition(10);
			printerMsg(messageType::score, to_string(score));
			printerMsg(messageType::ammunition, to_string(gun->getAmmunition()));
			printerMsg(messageType::info_delay	, "Bought ammunition");
			return served;
		}
		else
			printerMsg(messageType::info_delay, "not enough");
	default:
		return action;
	}
}
