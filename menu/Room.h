#pragma once
#include "Frame.h"
#include "Player.h"
#include "GameAction.h"
#include <vector>
#include "RoomElement.h"
#include "RoomMapBuilder.h"

using namespace std;

class Room : public Frame
{
public:
	Room() :Frame(45, 15) {};
	virtual void printFrame();
	virtual void printInside();
    virtual bool isInside(int row, int column);
	void setMap(vector<vector<RoomElement>> roomMap) {
		this->roomMap = roomMap;
	}

	void setPlayer(Player* player) {
		this->player = player;
		if (this->player == NULL)
			return;
		int column,row;
		while (getMapElement(column = rand() % width, row = rand() % height).id != room_inner.id);
		(*player).print(column, row);
	}
	GameAction runAction(GameAction action);
private:
	GameAction playerGoTo(int column, int row);
	RoomElement getMapElement(int column, int row);
	void setMapElement(int column, int row, RoomElement value);
	Player *player;
	vector<vector<RoomElement>> roomMap;
};