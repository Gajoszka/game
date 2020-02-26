#include "Room.h"
#include "Frame.h"
#include "Screen.h"
#include <iostream>
#include "RoomMap.h"
#include "Creature.h"

using namespace std;
template<typename Base, typename T>
inline bool instanceof(const T*) {
	return is_base_of<Base, T>::value;
}

void Room::printFrame()
{
}

void Room::printInside() {
	for (int row = 0; row < roomMap.getHeight(); row++) {
		for (int column = 0; column < roomMap.getWidth(); column++) {
			printPoint(column, row, (*roomMap.get(column,row)).icon);
		}
	}
}

void Room::setMap(RoomMap roomMap) {
	enemys.clear();
	this->roomMap = roomMap;
	//for (vector<RoomElement> row :this->roomMap) {
		//for (RoomElement el : row) {
			//if (el.getId() > 100) {
				//Enemy enemy = static_cast<Enemy>(el);
				//enemys.push_back(enemy);
			//}
		//}
//	}
}


void Room::setMapElement(int mapColumn, int mapRow, RoomElement value) {
	if (roomMap.set(mapColumn, mapRow, value))
		printPoint(mapColumn, mapRow, value.icon);
}


void Room::setMapElement(int mapColumn, int mapRow, Creature* value) {
	setMapElement(mapColumn, mapRow, *value);
	(*value).setRoomLocation(mapColumn, mapRow);
}


bool Room::isInside(int mapColumn, int mapRow) {
	return roomMap.canMove(mapColumn, mapRow);
}

void Room::enemyMove(Enemy* enemy, int columnStep, int rowStep) {
	int actColumn = (*enemy).getRoomLocation().getColumn() + columnStep;
	int actRow = (*enemy).getRoomLocation().getRow() + rowStep;
	if (!isInside(actColumn, actRow)) {
		enemyMove(enemy, -columnStep, -rowStep);
	}
	else {
		setMapElement((*enemy).getRoomLocation().getColumn(), (*enemy).getRoomLocation().getRow(), room_inner);
		Sleep(15);
		setMapElement(actColumn, actRow, enemy);
	}
}


void Room::enemyMove() {
	if (enemys.size() > 0 && rand() % 4 == 0) {
		Sleep(15);
		for (Enemy enemy : enemys) {
			enemyMove(&enemy, 0, 1);
		}
	}
}

GameAction Room::playerMove(int columnStep, int rowStep) {
	int actColumn = (*player).getRoomLocation().getColumn() + columnStep;
	int actRow = (*player).getRoomLocation().getRow() + rowStep;
	printPoint((*player).getRoomLocation().getColumn(), (*player).getRoomLocation().getRow(), ' ');
	Sleep(15);
	if (roomMap.isDoor(actColumn, actRow))
		return exitRoom;
	if (!isInside(actColumn, actRow)) {
		actColumn = (*player).getRoomLocation().getColumn();
		actRow = (*player).getRoomLocation().getRow();
	}
	else {

		(*player).addScore(roomMap.getScore(actColumn, actRow));
		roomMap.setInner(actColumn, actRow);
	}
	setMapElement(actColumn, actRow, player);

	return served;
}

GameAction Room::runAction(GameAction action)
{
	enemyMove();
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
		enemyMove();
		return served;
	default:
		return action;
	}
}

