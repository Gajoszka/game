#pragma once
#include <math.h>
#include "Room.h"
class Player
{
public:
	Player();

	const char P = '@';
	void printPlayer(int x, int y);
	int x;
	int y;
	char getP() {
		return P;
	};
	int getX() {
		return x;
	};
	int getY() {
		return y;
	};
	void setX(int value) {
		x = value;
	};
	void setY(int value) {
		y = value;
	};
};

