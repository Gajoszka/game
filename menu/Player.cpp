#include "Player.h"
#include "Room.h"
#include "Frame.h"
#include "KeyFunctions.h"
#include "Screen.h"
#include <iostream>

using namespace std;

Player::Player() {
	
}

bool Player::playerGoTo(int x, int y) {
	int xAct = player.x + x;
	int yAct = player.y + y;
	room.printPoint(player.x, player.y, ' ');
	Sleep(30);
	bool result = true;
	if (!room.isInside(xAct, yAct)) {
		xAct = player.x;
		yAct = player.y;
		result = false;
	}
	player.setX(xAct);
	player.setY(yAct);
	room.printPoint(xAct, yAct, player.getP());
	return result;
}
}
