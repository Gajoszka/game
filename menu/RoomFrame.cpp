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

void RoomFrame::setRoom(Room room) {
	this->room = room;
	if (player != NULL) {
		int i = 0;
		while (i < 50 && !room.setPlayer((rand() % (width - 2)) + 1, (rand() % (height - 2)) + 1, player))
			i++;
	}
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



// setting player position on a map
void RoomFrame::setPlayer(Player* player) {
	this->player = player;
	if (this->player == NULL)
		return;
	room.setPlayer(player);
	setMapElement(player->getLocation().getColumn(), player->getLocation().getRow(), player);
}

// player movement
GameAction RoomFrame::playerMove(int columnStep, int rowStep) {
	Point actLocation = (*player).getLocation();
	return room.movePlayer(columnStep, rowStep, player);
}


// defining arrow keys
GameAction RoomFrame::runAction(GameAction action)
{
	switch (action)
	{
	case served:
		return action;
	case key_up:
		return playerMove(0, -1);
	case key_down:
		return playerMove(0, 1);
	case key_left:
		return playerMove(-1, 0);
	case key_right:
		return playerMove(1, 0);
	case moveEnemy:
		room.moveEnemys();
		return served;
	default:
		return action;
	}
}

