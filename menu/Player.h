#pragma once
/*Player class defining players point, health...*/
#include <math.h>
#include <string>
#include "Creature.h"
#include <string>
using namespace std;

class Player:public Creature
{
public:
	Player(std::string name) :  Creature(50,'@', 10, 4, 3) {
		this->name = name;
	};

	void addScore(int s);
	int getScore();
	string getName();

private:
	int score = 0;
	std::string name;
};

