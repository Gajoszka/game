#pragma once
#include "Frame.h"
#include "Player.h"
#include "GameAction.h"
#include <vector>
#include "RoomElement.h"
#include "RoomMap.h"
#include "Enemy.h"
#include <ctime>

//using namespace std;

class RoomFrame : public Frame
{
public:
	RoomFrame(int width, int height) :Frame(width,height) , roomMap(1, 1) {
		last_move_enemy_time = clock() / CLOCKS_PER_SEC;
	};
	virtual void printInside();
    virtual bool isInside(int row, int column);
	void setMap(RoomMap roomMap);

	void setPlayer(Player* player) {
		this->player = player;
		if (this->player == NULL)
			return;
		roomMap.setPlayer(player);
		setMapElement(player->getLocation().getColumn(),player->getLocation().getRow(),player);
	}
	GameAction runAction(GameAction action);
protected:
	virtual void moveCursor(int column, int row);
private:
	GameAction playerMove(int column, int row);
	void enemyMove(Enemy enemy);
	void enemysMove();
	void setMapElement(int column, int row, RoomElement value);
	void setMapElement(int column, int row, Creature* value);
	Player *player;
	RoomMap roomMap;
	clock_t last_move_enemy_time;
};