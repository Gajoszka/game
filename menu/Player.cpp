#include "Player.h"
#include "Dungeon.h"
#include "KeyFunctions.h"
#include "Screen.h"
#include <iostream>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_END 79

using namespace std;

void Player::playerSpace() {
	Dungeon coor;
	bool ok = x >= coor.width || x <= coor.x || y >= coor.height || y <= coor.y;
	while (x >= 45 || x <= 1 || y >= 15 || y <= 1) {
		placeUser();
	};
	gotoxy(x, y);
	cout << user;
};

void Player::placeUser() {
	x = rand();
	y = rand();
};

