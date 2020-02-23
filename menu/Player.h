#pragma once
#include <math.h>
#include "Room.h"
#include "Creature.h"

class Player : public Creature
{
public:
	Player();
	bool playerGoTo(int x, int y);
	const char P = '@';
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

