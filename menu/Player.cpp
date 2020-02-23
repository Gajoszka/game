#include "Player.h"
#include "Room.h"
#include "Frame.h"
#include "KeyFunctions.h"
#include "Screen.h"
#include <iostream>

using namespace std;

Player::Player() {
	this->creature = P;
}

bool Player::playerGoTo(int x, int y) {
	int xAct = this->x + x;
	int yAct = this->y + y;
	room.printPoint(this->x, this->y, ' ');
	Sleep(30);
	bool result = true;
	if (!room.isInside(xAct, yAct)) {
		xAct = this->x;
		yAct = this->y;
		result = false;
	}
	setX(xAct);
	setY(yAct);
	room.printPoint(xAct, yAct, getP());
	return result;
}
