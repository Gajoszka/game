#pragma once
/* Manage what's inside room walls,
controls movements of creatures*/
#include "Frame.h"
#include "Player.h"
#include "GameAction.h"
#include <vector>
#include "RoomElement.h"
#include "Room.h"
#include "Enemy.h"


using namespace std;

class RoomFrame : public Frame
{
public:
	RoomFrame(int width, int height) :Frame(width,height) , room(1, 1) {
	
	};
	virtual void printInside();
    virtual bool isInside(int row, int column);
	void setRoom(Room room);
	void setPlayer(Player* player);
	GameAction runAction(GameAction action);
protected:
	virtual void moveCursor(int column, int row);
private:
	GameAction playerMove(int column, int row);
	void setMapElement(int column, int row, RoomElement value);
	void setMapElement(int column, int row, Creature* value);
	Player *player;
	Room room;
	
};