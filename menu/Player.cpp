#include "Player.h"
#include <iostream>
#include <string>
using namespace std;

void Player::addScore(int s) {
	score = score + s;
	printMsg(messageType::score, to_string(score));
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
	room->putInInner( this);
}


GameAction Player::move(int columnStep, int rowStep) {
	RoomElement* actEl = room->get(getLocation().getColumn() + columnStep, getLocation().getRow() + rowStep);
	GameAction action = actEl->conflict(this);
	if (action == can_move || action == exitRoom) {
		GameAction action1 = room->moveCreature(getLocation().getColumn() + columnStep, getLocation().getRow() + rowStep, 20, this);
		if (action != exitRoom)
			return action1;
	}
	return action;
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
	default:
		return action;
	}
}
