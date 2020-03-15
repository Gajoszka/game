#pragma once
#include "GameDef.h"	
//#include "Player.h"
class Player;

class RoomElement {
public:
	RoomElement(int id, char icon, bool canPass) {
		this->id = id;
		this->icon = icon;
		this->canPass = canPass;
	}
	RoomElement(int id, char icon, bool canPass, int score) {
		this->id = id;
		this->icon = icon;
		this->canPass = canPass;
		this->score = score;
	}
	int getId() {
		return id;
	}
	virtual GameAction conflict(Player* player);
	int id = 0;
	char icon = ' ';
	bool canPass = true;
protected:
	int score = 0;
};

