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
		this->pLayout = layout;
	}
	void setPlayer(Player* player) {
		this->pPlayer = player;
	}
	Room* getRoom();
	void createRoom();
	GameAction runAction(GameAction action);
	~Floor();
private:
	RoomElementFactory elementFactory;
	Room* pActRoom=nullptr;
	Player* pPlayer;
	GameLayout* pLayout;
	int roomNr = 0;
	void exitFromRoom();
};

