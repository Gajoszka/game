#include "Player.h"
#include <iostream>
#include <string>
#include "Screen.h"
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

void Player::boom()
{
	
	for (int i = 1; i < 3; i++) {
		RoomElement*  actEl0 = room->get(getLocation().getColumn()+1, getLocation().getRow());
		if (actEl0->canPass) {
			room->printer(getLocation().getColumn() + 1, getLocation().getRow(), '.');
		}
		delay(10);
		RoomElement*  actEl1 = room->get(getLocation().getColumn() - 1, getLocation().getRow());
		if (actEl1->canPass) {
			room->printer(getLocation().getColumn() - 1, getLocation().getRow(), '.');
			delay(10);
		}
		RoomElement* actEl2 = room->get(getLocation().getColumn() , getLocation().getRow()+1);
		if (actEl2->canPass) {
			room->printer(getLocation().getColumn(), getLocation().getRow() + 1, '.');
			delay(10);
		}
		RoomElement* actEl3 = room->get(getLocation().getColumn() , getLocation().getRow()-1);
		if (actEl3->canPass) {
			room->printer(getLocation().getColumn(), getLocation().getRow() - 1, '.');
		}
		delay(50);
		room->printer(getLocation().getColumn() + 1, getLocation().getRow(), actEl0->icon);
		delay(10);
		room->printer(getLocation().getColumn() - 1, getLocation().getRow(), actEl1->icon);
		delay(10);
		room->printer(getLocation().getColumn(), getLocation().getRow() + 1, actEl2->icon);
		delay(10);
		room->printer(getLocation().getColumn(), getLocation().getRow() - 1, actEl3->icon);
		delay(30);
	}
	room->printer(getLocation().getColumn(), getLocation().getRow(), icon);
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
