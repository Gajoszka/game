#include "Room.h"
#include "Frame.h"
#include "Screen.h"
#include <iostream>


void Room::printFrame()
{
}


void Room::printInside() {
	for (int row = 0; row < height; row++) {
		for (int column = 0; column < width; column++) {
			printPoint(column , row , getSign(roomMap[row][column]));
		}
	}
}


char Room::getMapElement(int column, int row) {
	int indexColumn = column - getTopLeft().getColumn();
	int  indexRow = row  - getTopLeft().getRow();
	if (indexRow >= 0 && indexColumn >= 0 && indexRow < height && indexColumn <= width)
		return  roomMap[indexRow][indexColumn];
	return -10;
}


void Room::setMapElement(int column, int row, int value) {
	int indexColumn = column - getTopLeft().getColumn();
	int  indexRow = row - getTopLeft().getRow();
	if (indexRow >= 0 && indexColumn >= 0 && indexRow < height && indexColumn <= width )
		roomMap[indexRow][indexColumn]=value;
}

bool Room::isInside(int column, int row) {
	return getMapElement(column,row) != 1 && getMapElement(column,row) != 2;
}



GameAction Room::playerGoTo(int columnStep, int rowStep) {
	int actColumn = (*player).getLocation().getColumn() + columnStep;
	int actRow = (*player).getLocation().getRow() + rowStep;
	(*player).clear();
	Sleep(15);
	bool result = true;
	if (getMapElement(actColumn, actRow) == -1)
		return exitRoom;
	if (!isInside(actColumn, actRow)) {
		actColumn = (*player).getLocation().getColumn();
		actRow = (*player).getLocation().getRow();
		result = false;
	}
	else if (getMapElement(actColumn, actRow)==10) {
		(*player).addScore(2);
		setMapElement(actColumn, actRow,0);
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
		return playerGoTo(-1,0);
	case key_right:
		return playerGoTo(1,0);
	default:
		return action;
	}
}

char Room::getSign(int value) {
	switch (value) {
	case -1:
		return ' ';
	case 0:
		return ' ';
	case 1:
		return static_cast<char>(219);
	case 2:
		return static_cast<char>(178);
	case 10:
		return static_cast<char>(240);
	default:
		return ' ';
	}
}

