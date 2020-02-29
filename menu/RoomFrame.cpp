#include "RoomFrame.h"
#include "Screen.h"
#include <iostream>
#include "Room.h"
#include "Creature.h"

using namespace std;
//template<typename Base, typename T>
//inline bool instanceof(const T*) {
//	return is_base_of<Base, T>::value;
//}

// setting cursor position
void RoomFrame::moveCursor(int column, int row) {
	gotoxy(topLeft.getColumn() +2+column, 2+topLeft.getRow() + row);
}

// pritning map elements
void RoomFrame::printInside() {
	for (int row = 0; row < room.getHeight(); row++) {
		for (int column = 0; column < room.getWidth(); column++) {
			printPoint(column, row, room.getIcon(column, row));
		}
	}
}

void RoomFrame::setRoom(Room* room) {
	this->room = *room;
	
	using namespace std::placeholders;
	this->room.setPrinter(std::bind(&RoomFrame::printPoint, this, _1, _2, _3));
	
}


void RoomFrame::setMapElement(int mapColumn, int mapRow, RoomElement value) {
	if (room.set(mapColumn, mapRow, value))
		printPoint(mapColumn, mapRow, value.icon);
}


void RoomFrame::setMapElement(int mapColumn, int mapRow, Creature* value) {
	setMapElement(mapColumn, mapRow, *value);
	(*value).setLocation(mapColumn, mapRow);
}

bool RoomFrame::isInside(int mapColumn, int mapRow) {
	return room.canPlayerMove(mapColumn, mapRow);
}



// defining arrow keys
GameAction RoomFrame::runAction(GameAction action)
{
	switch (action)
	{
	case served:
		return action;
	case key_up:
		return room.movePlayer(0, -1);
	case key_down:
		return room.movePlayer(0, 1);
	case key_left:
		return room.movePlayer(-1, 0);
	case key_right:
		return room.movePlayer(1, 0);
	case moveEnemy:
		room.moveEnemys();
		return served;
	default:
		return action;
	}
}

