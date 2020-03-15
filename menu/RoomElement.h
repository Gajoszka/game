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
	int getId() {
		return id;
	}
	virtual GameAction conflict(Player* player) {
		return canPass ? can_move : stop;
	}
	int id = 0;
	char icon = ' ';
	bool canPass = true;
private:

};

