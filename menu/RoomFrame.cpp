#include "RoomFrame.h"
#include "Screen.h"
#include <iostream>
#include "Room.h"
#include "Creature.h"
/* Manages what's inside room walls*/
using namespace std;


// setting cursor position
void RoomFrame::moveCursor(int column, int row) {
	gotoxy(topLeft.getColumn() +2+column, 2+topLeft.getRow() + row);
}

// pritning map elements
void RoomFrame::printInside() {
	if (room == nullptr)
		return;
	for (int row = 0; row < (*room).getHeight(); row++) {
		for (int column = 0; column < (*room).getWidth(); column++) {
			printPoint(column, row, (*room).getIcon(column, row));
		}
	}
}

void RoomFrame::setRoom(Room* room) {
	this->room = room;
	using namespace placeholders;
	(*this->room).setPrinter(bind(&RoomFrame::printPoint, this, _1, _2, _3)); //bind - adjusting parameters
	
}

bool RoomFrame::isInside(int mapColumn, int mapRow) {
	return (*room).isInner(mapColumn, mapRow);
}

// defining arrow keys
GameAction RoomFrame::runAction(GameAction action)
{
	switch (action)
	{
	case served:
		return action;
	case moveEnemy:
		(*room).moveEnemys();
		return served;
	default:
		return action;
	}
}