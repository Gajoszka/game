#include "RoomFrame.h"
#include "Screen.h"
#include <iostream>
#include "RoomMap.h"
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
	for (int row = 0; row < roomMap.getHeight(); row++) {
		for (int column = 0; column < roomMap.getWidth(); column++) {
			printPoint(column, row, roomMap.getIcon(column, row));
		}
	}
}

void RoomFrame::setMap(RoomMap roomMap) {
	this->roomMap = roomMap;
	if (player != NULL) {
		int i = 0;
		while (i < 50 && !roomMap.setPlayer((rand() % (width - 2)) + 1, (rand() % (height - 2)) + 1, player))
			i++;
	}
}


void RoomFrame::setMapElement(int mapColumn, int mapRow, RoomElement value) {
	if (roomMap.set(mapColumn, mapRow, value))
		printPoint(mapColumn, mapRow, value.icon);
}


void RoomFrame::setMapElement(int mapColumn, int mapRow, Creature* value) {
	setMapElement(mapColumn, mapRow, *value);
	(*value).setLocation(mapColumn, mapRow);
}


bool RoomFrame::isInside(int mapColumn, int mapRow) {
	return roomMap.canMove(mapColumn, mapRow);
}

// enemy movement
void RoomFrame::enemyMove(Enemy enemy) {
	int columnStep, rowStep;
	Point actLocation = enemy.getLocation();
	int i = 0;
	bool ok = false;
	while (i < 6 && !ok) { // i < 6 so the loop is not infinite
		rowStep = (rand() % 3) - 1;
		columnStep = (rand() % 3) - 1;
		ok = roomMap.moveEnemy(columnStep, rowStep, enemy); //enemy is within room walls
		i++;
	}
	if (ok) {
		printPoint(actLocation.getColumn(), actLocation.getRow(), roomMap.getIcon(actLocation.getColumn(), actLocation.getRow()));
		Sleep(15);
		enemy = roomMap.getEnemy(enemy.id);
		printPoint(enemy.getLocation().getColumn(), enemy.getLocation().getRow(), enemy.icon);
	}
}

// time between enemies moves
void RoomFrame::enemysMove() {
	time_t current_time = time(NULL);
	if (clock() / CLOCKS_PER_SEC - last_move_enemy_time < 0.5)
		return;
	last_move_enemy_time = clock() / CLOCKS_PER_SEC;
	for (Enemy enemy : roomMap.getEnemys()) {
		enemyMove(enemy);
		Sleep(15);
	}
}


// setting player position on a map
void RoomFrame::setPlayer(Player* player) {
	this->player = player;
	if (this->player == NULL)
		return;
	roomMap.setPlayer(player);
	setMapElement(player->getLocation().getColumn(), player->getLocation().getRow(), player);
}

// player movement
GameAction RoomFrame::playerMove(int columnStep, int rowStep) {
	Point actLocation = (*player).getLocation();
	GameAction action = roomMap.movePlayer(columnStep, rowStep, player);
	if (action == exitRoom) { // checking if player left the room, if so setting his position in a new one
		printPoint(actLocation.getColumn(), actLocation.getRow(), room_inner.icon);
		Sleep(10);
		printPoint(actLocation.getColumn() + columnStep, actLocation.getRow() + rowStep, (*player).icon);
	}
	else { // if not, canging his position
		printPoint(actLocation.getColumn(), actLocation.getRow(), roomMap.getIcon(actLocation.getColumn(), actLocation.getRow()));
		Sleep(15);
		printPoint((*player).getLocation().getColumn(), (*player).getLocation().getRow(), (*player).icon);
	}return action;
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
		enemysMove();
		return served;
	default:
		return action;
	}
}

