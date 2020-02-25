#include "Room.h"
#include "Frame.h"
#include "Screen.h"
#include <iostream>
#include "RoomMapBuilder.h"


void Room::printFrame()
{
}

void Room::printInside() {
	for (int row = 0; row < roomMap.size(); row++) {
		for (int column = 0; column < width; column++) {
			printPoint(column, row, roomMap[row][column].icon);
		}
	}
}

RoomElement Room::getMapElement(int column, int row) {
	int indexColumn = column - getTopLeft().getColumn();
	int  indexRow = row - getTopLeft().getRow();
	if (indexRow >= 0 && indexColumn >= 0 && indexRow < height && indexColumn <= width)
		return  roomMap[indexRow][indexColumn];
	return room_wall;
}

void Room::setMapElement(int column, int row, RoomElement value) {
	int indexColumn = column - getTopLeft().getColumn();
	int  indexRow = row - getTopLeft().getRow();
	if (indexRow >= 0 && indexColumn >= 0 && indexRow < height && indexColumn <= width)
		roomMap[indexRow][indexColumn] = value;
}

bool Room::isInside(int column, int row) {
	return getMapElement(column, row).canGo;
}

GameAction Room::playerGoTo(int columnStep, int rowStep) {
	int actColumn = (*player).getLocation().getColumn() + columnStep;
	int actRow = (*player).getLocation().getRow() + rowStep;
	(*player).clear();
	Sleep(15);
	bool result = true;
	if (getMapElement(actColumn, actRow).id == room_door.id)
		return exitRoom;
	if (!isInside(actColumn, actRow)) {
		actColumn = (*player).getLocation().getColumn();
		actRow = (*player).getLocation().getRow();
		result = false;
	}
	else {
		RoomElement rm = getMapElement(actColumn, actRow);
		(*player).addScore(rm.score);
		setMapElement(actColumn, actRow, room_inner);
	}
	(*player).print(actColumn, actRow);

	return served;
}

GameAction Room::runAction(GameAction action)
{
	switch (action)
	{
	case served:
		return action;
	case key_up:
		return playerGoTo(0, -1);
	case key_down:
		return playerGoTo(0, 1);
	case key_left:
		return playerGoTo(-1, 0);
	case key_right:
		return playerGoTo(1, 0);
	default:
		return action;
	}
}

