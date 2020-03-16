#pragma once
#include "GameDef.h"	
class Creature;

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
	virtual GameAction conflict(Creature* player);
	int id = 0;
	char icon = '\u0032';
	bool canPass = true;
	int score = 0;
};
	

