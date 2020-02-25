#pragma once
#include "Frame.h"
#include "Player.h"
#include "GameAction.h"
#include <vector>

using namespace std;

#define sign_room_wall  static_cast<char>(219);
#define sign_room_door static_cast<char>(32);
#define sign_room_inside static_cast<char>(32);
#define sign_obstacle static_cast<char>(178);
#define sign_treasure static_cast<char>(158);

class Room : public Frame
{
public:
	Room() :Frame(45, 15) {};
	virtual void printFrame();
	virtual void printInside();
    virtual bool isInside(int row, int column);
	void setMap(vector<vector<int>> roomMap) {
		this->roomMap = roomMap;
	}

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
	GameAction playerGoTo(int column, int row);
	char getMapElement(int column, int row);
	void setMapElement(int column, int row, int value);
	Player *player;
	char getSign(int value);
	vector<vector<int>> roomMap;
};