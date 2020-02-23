#include "Room.h"
#include "Frame.h"
#include "keyfunctions.h"
#include "Stats.h"
#include "Screen.h"
#include <vector>
#include <iostream>


using namespace std;

Room::Room(int map[15][45]) : Frame(45 ,15) {
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


bool Room::isInside(int x, int y) {
	int indexX = x - getTop().getX();
	int indexY = y - getTop().getY();
	return indexX>=0 && indexY>= 0 && indexX<width && indexY<=height && arenaMap[indexY][indexX] != 1;
}

char Room::getSign(int value) {
	switch (value) {
	case 0:
		return ' ';
	case 1:
		return 'X';
	case 2:
		return 'S';
	default:
		return ' ';
	}
}