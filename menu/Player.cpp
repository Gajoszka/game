#include "Player.h"
#include "Dungeon.h"
#include "Frame.h"
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
	//Frame coor(20,20);
	/*coor.isInside(21, 11);
	bool ok = (x >= coor.width || x <= coor.x) &&  (y >= coor.height || y <= coor.y);
	while (obj.isInside()) {
		placeUser();
	};*/
	gotoxy(x, y);
	cout << user;
};

void Player::placeUser() {
	x = rand();
	y = rand();
};

