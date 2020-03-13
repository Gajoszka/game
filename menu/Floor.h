#pragma once
#include "Room.h"
#include "GameLayout.h"

class Floor
{
public:
	Floor():actRoom(0, 0) {
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
private:

	Room actRoom;
	Player* player;
	GameLayout* layout;
	int roomNr = 0;
	void exitFromRoom();
};

