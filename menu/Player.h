#pragma once
#include <math.h>
#include "Room.h"
#include "Creature.h"
#include "GameManager.h"

class Player : public Creature
{
public:
	Player() : creature(10, 4, 3) {};
	virtual bool playerGoTo(int x, int y);
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
private:
	Creature creature;
};

