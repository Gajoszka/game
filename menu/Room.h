#pragma once
#include "Frame.h"
#include "Player.h"
#include "GameAction.h"


class Room : public Frame
{
public:
	Room() :Frame(45, 15) {};
	virtual void printFrame();
	virtual void printInside();
    virtual bool isInside(int x, int y);
	void setMap(int map[15][45]);
	void setPlayer(Player* player) {
		this->player = player;
		if (this->player == NULL)
			return;
		int x,y;
		while (getMapElement(x = rand() % 45, y = rand() % 18) != 0);
		(*player).print(x, y);
	}
	GameAction runAction(GameAction action);
private:
	GameAction playerGoTo(int x, int y);
	char getMapElement(int x, int y);
	Player *player;
	char getSign(int x);
	int arenaMap[15][45];
};