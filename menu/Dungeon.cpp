#include "Dungeon.h"
#include<iostream>
#include <stdlib.h>
#include <vector>
#include <random>

using namespace std;

random_device rd;
mt19937 mt(rd());


int Dungeon::randomInt(int min, int max) {
	uniform_int_distribution<> dist(0, max - min);
	return dist(mt) + min;
}

void Dungeon::createRoom(int x, int y, Directions dir, bool firstRoom = false) {
	const int minRoomSize = 5;
	const int maxRoomSize = 15;

	Rect room;
	room.width = randomInt(minRoomSize, maxRoomSize);
	room.height = randomInt(minRoomSize, maxRoomSize);

	if (dir == North) {
		room.x = x - room.width / 2;
		room.y = y - room.height / 2;
	}
	else if (dir == South) {
		room.x = x - room.width / 2;
		room.y = y + 1;
	}

	else if (dir == West) {
		room.x = x - room.width;
		room.y = y - room.height / 2;
	}

	else if (dir == East) {
		room.x = x + 1;
		room.y = y - room.height / 2;
	}
}