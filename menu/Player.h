#pragma once
/*Player class defining players point, health...*/
#include <math.h>
#include <string>
#include "Creature.h"
#include <string>
#include "GameDef.h"
#include "GameType.h"
using namespace std;

class Player:public Creature
{
public:
	Player(std::string name) :  Creature(50,sign_player, 10, 4, 3) {
		this->name = name;
	};
	void setPrinterMessage(printMessage printer) {
		this->printMsg = printer;
	}
	void addScore(int s);
	int getScore();
	string getName();

private:
	int score = 0;
	std::string name;
	printMessage printMsg=nullptr;
};

