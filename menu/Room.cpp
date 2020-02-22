#include "Room.h"
#include "Frame.h"
#include "keyfunctions.h"
#include "Stats.h"
#include "Screen.h"
#include <vector>
#include <iostream>


using namespace std;

Room::Room() : Frame(45,15) {
	
}

void Room::printInside() {
	for (int i = 0; i < 45; i++) {
		for (int j = 0; j < 15; j++) {
			printPoint(i + 1, j + 1, room[i][j] == 0 ? ' ' : 'X');
		}
	}
}