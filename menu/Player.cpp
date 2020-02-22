#include "Player.h"
#include "Room.h"
#include "Frame.h"
#include "KeyFunctions.h"
#include "Screen.h"
#include <iostream>

using namespace std;

void Player::printPlayer(int x, int y) {
	Frame check(45, 15);
	/*do {
		x = rand() % 45 + 3;
		y = rand() % 15 + 2;
	} while(room.isInside(x, y));*/

	gotoxy(x, y);
	cout << user;
};

