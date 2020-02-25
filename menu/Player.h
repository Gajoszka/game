#pragma once
#include <math.h>
#include <string>
#include "Creature.h"


class Player:public Creature
{
public:
	Player(std::string name) :  Creature(50,'@', 10, 4, 3) {
		this->name = name;
	};

	void addScore(int s) {
		score = score + s;
	}
	int getScore() {
		return score;
	}
	std::string getName() {
		return name;
	}

private:
	int score = 0;
	std::string name;
	

	
};

