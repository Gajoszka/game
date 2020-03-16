#pragma once
/*Player class defining players point, health...*/
#include <math.h>
#include <string>
#include "Creature.h"
#include <string>
#include "GameDef.h"
#include "GameType.h"
#include "Gun.h"
#include "Room.h"

using namespace std;

class Player :public Creature
{
public:
	Player(string name) : Creature(id_player, sign_player, 10, 4, 3) {
		this->name = name;
		gun = new Gun(6, 50);

	};
	Player() : Creature(id_player, sign_player, 10, 4, 3) {
		gun = new Gun(6, 100);
	};
	void setName(string name) {
		this->name = name;
	};

	void setPrinterMsg(printMessage printer) {
		this->printerMsg = printer;
	}

	GameAction runAction(GameAction action);
	GameAction move(int columnStep, int rowStep);
	void addScore(int s);
	int getScore();
	string getName();

	void setRoom(Room* room);
	void  boom();
	Room* getRoom() {
		return room;
	}
	~Player();
private:
	int score = 0;
	std::string name;
	printMessage printerMsg = nullptr;
	Room* room;
	Gun* gun = nullptr;
	GameAction shot();
};

