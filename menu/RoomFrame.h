#pragma once
/* Manage what's inside room walls,
controls movements of creatures*/
#include "Frame.h"
#include "Player.h"
#include "GameDef.h"
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
	void setRoom(Room* room);
	GameAction runAction(GameAction action);
protected:
	virtual void moveCursor(int column, int row);
private:
	void setMapElement(int column, int row, RoomElement value);
	void setMapElement(int column, int row, Creature* value);
	
	Room room;
	
};