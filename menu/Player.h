#pragma once
#include <math.h>
#include "Creature.h"

class Player:public Creature
{
public:
	Player() :Creature('@', 10, 4, 3) {};

	void addScore(int s) {
		score = score + s;
	}
	int getScore() {
		return score;
	}
private:
	int score = 0;
	

	
};

