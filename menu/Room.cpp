#include "Room.h"
#include "Frame.h"
#include "keyfunctions.h"
#include "Stats.h"
#include "Screen.h"
#include <vector>
#include <iostream>
#include "GameAction.h"


using namespace std;

void Room::setMap(int map[15][45]) {
	if (map!=NULL)
	for (int j = 0; j < height; j++) {
		for (int i = 0; i < width; i++) {
			arenaMap[j][i]=map[j][i];
		}
	}

}

void Room::printFrame()
{
}


void Room::printInside() {
	for (int j = 0; j < height; j++) {
		for (int i = 0; i < width; i++) {
			printPoint(i , j , getSign(arenaMap[j][i]));
		}
	}
}


char Room::getMapElement(int x, int y) {
	int indexX = x - getTop().getX();
	int indexY = y - getTop().getY();
	if ( indexX >= 0 && indexY >= 0 && indexX < width && indexY <= height )
		return  arenaMap[indexY][indexX];
	return -10;
}

bool Room::isInside(int x, int y) {
	return getMapElement(x,y) != 1 && getMapElement(x, y) != 2;
}



GameAction Room::playerGoTo(int x, int y) {
	int xAct = (*player).getLocation().getX() + x;
	int yAct = (*player).getLocation().getY() + y;
	(*player).clear();
	Sleep(20);
	bool result = true;
	if (getMapElement(xAct, yAct) == -1)
		return exitRoom;
	if (!isInside(xAct, yAct)) {
		xAct = (*player).getLocation().getX();
		yAct = (*player).getLocation().getY();
		result = false;
	}
	(*player).print(xAct, yAct);
	return served;
}

GameAction Room::runAction(GameAction action)
{
	switch (action)
	{
	case served:
		return action;
	case key_up:
		return playerGoTo(0, -1);
	case key_down:
		return playerGoTo(0, 1);
	case key_left:
		return playerGoTo(-1,0);
	case key_right:
		return playerGoTo(1,0);
	default:
		return action;
	}
}

char Room::getSign(int value) {
	switch (value) {
	case -1:
		return ' ';
	case 0:
		return ' ';
	case 1:
		return 219;
	case 2:
		return 218;
	case 10:
		return 'S';
	default:
		return ' ';
	}
}

