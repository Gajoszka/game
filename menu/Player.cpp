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
	Point place = (*room).getRandomInner();
	(*room).put(place.getColumn(), place.getRow(), this);
	setLocation(place);
}

//	//while (!setPlayer(rand() % width, rand() % height, player));
//	return true;
//}


GameAction Player::move(int columnStep, int rowStep) {
	int actColumn = getLocation().getColumn();
	int actRow = getLocation().getRow();
	RoomElement* actEl = (*room).get(actColumn + columnStep, actRow + rowStep);
	if ((*actEl).canPass) {
		//if ((*actEl).getId() != room_inner.id)
			(*actEl).conflict(this);
		return (*room).motionSimulation(getLocation().getColumn() + columnStep, getLocation().getRow() + rowStep, this);
	}
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
		//case moveEnemy:
		//	room.moveEnemys();
		//	return served;
	default:
		return action;
	}
}
