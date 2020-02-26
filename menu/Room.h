#pragma once
#include "Frame.h"
#include "Player.h"
#include "GameAction.h"
#include <vector>
#include "RoomElement.h"
#include "RoomMapBuilder.h"
#include "Enemy.h"

using namespace std;

class Room : public Frame
{
public:
	Room() :Frame(45, 15) {};
	virtual void printFrame();
	virtual void printInside();
    virtual bool isInside(int row, int column);
	void setMap(vector<vector<RoomElement>> roomMap);

	void setPlayer(Player* player) {
		this->player = player;
		if (this->player == NULL)
			return;
		int column,row;
		while (getMapElement(column = rand() % width, row = rand() % height).id != room_inner.id);
		setMapElement(column, row, player);
	}
	GameAction runAction(GameAction action);
private:
	GameAction playerMove(int column, int row);
	void enemyMove(Enemy* enemy, int columnStep, int rowStep);
	void enemyMove();
	RoomElement getMapElement(int column, int row);
	void setMapElement(int column, int row, RoomElement value);
	void setMapElement(int column, int row, Creature* value);
	Player *player;
	vector<Enemy*> enemys;
	vector<vector<RoomElement>> roomMap;
};