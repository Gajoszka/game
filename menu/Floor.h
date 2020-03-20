#pragma once
#include "Room.h"
#include "GameLayout.h"
#include"RoomElementFactory.h"
/* Creating floor with multiplle rooms */

class Floor
{
public:
	Floor():elementFactory(){
	}
	void setLayout(GameLayout* layout) {
		this->layout = layout;
	}
	void setPlayer(Player* player) {
		this->player = player;
	}
	Room* getRoom();
	void createRoom();
	GameAction runAction(GameAction action);
	~Floor();
private:
	RoomElementFactory elementFactory;
	Room* actRoom=nullptr;
	Player* player;
	GameLayout* layout;
	int roomNr = 0;
	void exitFromRoom();
};

