#pragma once
/*Defining players and their attributes and abilities*/
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

	};
	Player() : Creature(id_player, sign_player, 10, 4, 3) {
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
	GameAction decreseLives() {
		lives--;
		printerMsg(messageType::lives, to_string(lives));
		room->boomSimulation(this, false);
		return lives <= 0 ? player_death: served;
	}
	void setRoom(Room* room);
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
	int lives = 5;
	GameAction shot();
};