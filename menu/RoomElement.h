#pragma once
//#include "Player.h"
class Player;



class RoomElement {
public:
	RoomElement(int id, char icon, bool canPass, int score) {
		this->id = id;
		this->icon = icon;
		this->canPass = canPass;
		this->score = score;
	}
	int getId() {
		return id;
	}
	virtual void conflict(Player* player) {
		//(*player).addScore(score);
	}
	int id = 0;
	int score = 0;
	char icon = ' ';
	bool canPass = true;
private:

};

