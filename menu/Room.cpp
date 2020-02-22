#include "Room.h"
#include "Frame.h"
#include "keyfunctions.h"
#include "Stats.h"
#include "Screen.h"
#include <vector>
#include <iostream>


using namespace std;

Room::Room() : Frame(48 ,18) {
	widthRoom = 45;
	heightRoom = 15;
	generator();
}

void Room::generator() {
	for (int i = 0; i < widthRoom; i++) {
		for (int j = 0; j < heightRoom; j++) {
			room[i][j] = 0;
		}
	}
	for (int i = 0; i < widthRoom; i++) {
			room[i][0] = 1;
			room[i][heightRoom -1] = 1;
	}

	for (int i = 0; i < heightRoom; i++) {
		room[0][i] = 1;
		room[widthRoom-1][i] = 1;
	}
}

void Room::printInside() {
	for (int i = 0; i < 45; i++) {
		for (int j = 0; j < 15; j++) {
			printPoint(i + 2, j + 2, room[i][j] == 0 ? ' ' : 'X');
		}
	}
}

bool Room::isInside(int x, int y) {
	return room[x][y] == 0;
}

