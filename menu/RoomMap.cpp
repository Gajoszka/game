#include "RoomMap.h"


RoomMap::~RoomMap()
{
	enemys.clear();
	for (vector<RoomElement> v : roomMap) {
		v.clear();
	}
	roomMap.clear();
}


bool  RoomMap::set(int column, int row, RoomElement el) {
	if (row >= 0 && row < height && column >= 0 && column < width) {
		roomMap[row][column] = el;
		return true;
	}
	return false;
}
Enemy RoomMap::getEnemy(int column, int row) {
	return getEnemy(get(column, row).getId());

}

Enemy RoomMap::getEnemy(int id) {
	for (Enemy enemy : enemys) {
		if (enemy.id == id)
			return enemy;
	}
	return NULL;
}


bool RoomMap::setEnemy(int column, int row, Enemy enemy) {
	if (canPut(column, row))
		if (set(column, row, enemy)) {
			enemy.setLocation(column, row);
			enemy.id = enemy.id + 10000;
			enemys.push_back(enemy);
			return true;
		}
	return false;
}

bool RoomMap::moveEnemy(int columnStep, int rowStep, Enemy enemy) {
	int actColumn = enemy.getLocation().getColumn() + columnStep;
	int actRow = enemy.getLocation().getRow() + rowStep;
	if (!canMove(actColumn, actRow))
		return false;
	setInner(enemy.getLocation().getColumn(), enemy.getLocation().getRow());
	if (set(actColumn, actRow, enemy)) {
		for (int i = 0; i < enemys.size(); i++) {
			if (enemys[i].id == enemy.id) {
				enemys[i].setLocation(actColumn, actRow);
				break;
			}
		}
	}
}

GameAction RoomMap::movePlayer(int columnStep, int rowStep, Player* player) {
	int newColumn = (*player).getLocation().getColumn()  + columnStep;
	int newRow = (*player).getLocation().getRow()  + rowStep;
	if (isDoor(newColumn, newRow))
		return exitRoom;
	if (!canMove(newColumn, newRow))
		return served;
	setInner((*player).getLocation().getColumn(), (*player).getLocation().getRow());
	setPlayer(newColumn, newRow, player);
	return served;
}


bool RoomMap::setPlayer(Player* player) {

	while (!setPlayer(rand() % width, rand() % height, player));
	return true;
}


bool RoomMap::setPlayer(int column, int row, Player* player) {
	if (canMove(column, row))
		if (set(column, row, *player)) {
			(*player).setLocation(column, row);
			return true;
		}
	return false;
}

bool RoomMap::setDoor(int column, int row) {
	if ((column == 0 || column == width - 1 || row == 0 || row == height - 1)
		&& !(column == row)
		&& !(column == 0 && row == height - 1)
		&& !(column == width - 1 && row == 0)) {
		set(column, row, room_door);
		return true;
	}
	return false;
}

bool RoomMap::canPut(int column, int row) {
	if (roomMap[row][column - 1].id == room_door.id
		|| roomMap[row][column].id == room_wall.id
		|| roomMap[row][column + 1].id == room_door.id)
		return false;
	if (roomMap[row - 1][column].id != room_inner.id && roomMap[row + 1][column].id != room_inner.id)
		return false;
	return true;
}


