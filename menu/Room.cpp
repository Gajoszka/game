#include "Room.h"
#include "Screen.h"
#include "Treasure.h"


Room::Room(int width, int height) {
	last_move_enemy_time = clock() / CLOCKS_PER_SEC;
	this->width = width;
	this->height = height;;
	for (int row = 0; row < height; row++) {
		vector<RoomElement> tmp(width, *p_room_inner);
		roomMap.push_back(move(tmp));
	}
}

RoomElement* Room::get(int column, int row) {
	if (row >= 0 && row < height && column >= 0 && column < width) {
		return &roomMap[row][column];
	}
	return p_failed;
}
bool Room::setWall(int column, int row) {
	return put(column, row, p_room_wall);
}

bool Room::setScale(int column, int row) {
	if (isInner(column, row))
		return put(column, row, p_room_scale);
	return false;
}

bool Room::setTreasure(int column, int row) {
	if (isInner(column, row))
		return put(column, row, p_room_treasure);
	return false;
}

//bool Room::canPlayerMove(int column, int row) {
//	return get(column, row).canPass;
//}



bool Room::canEnemyMove(int column, int row) {
	RoomElement* el = get(column, row);
	return (*el).canPass && (*el).id != (*p_room_door).id && (*el).id != (*p_room_treasure).id;
}


bool Room::isEnemy(int column, int row) {
	return (*get(column, row)).id > 10000;
}

bool Room::setInner(int column, int row) {
	if ((*get(column, row)).id == (*p_room_door).id)
		return true;
	return put(column, row, p_room_inner);
}

Room::~Room()
{
	enemys.clear();
	for (vector<RoomElement> v : roomMap) {
		v.clear();
	}
	roomMap.clear();
}

bool  Room::put(int column, int row, RoomElement* el) {
	if (row >= 0 && row < height && column >= 0 && column < width) {
		roomMap[row][column] = *el;
		if (printer != nullptr)
			printer(column, row,(*el).icon);
		return true;
	}
	return false;
}
Enemy* Room::getEnemy(int column, int row) {
	return getEnemyById((*get(column, row)).getId());

}

Enemy* Room::getEnemyById(int id) {
	for (int i = 0; i < enemys.size(); ++i) {
		if (enemys[i].id == id)
			return &enemys[i];
	}
	return NULL;
}

bool Room::setEnemy(int column, int row, Enemy enemy) {
	if (isInner(column, row)) {
		if (put(column, row, &enemy)) {
			bool found = false;
			for (int i = 0; i < enemys.size(); i++) {
				if (enemys[i].id == enemy.id) {
					enemys[i].setLocation(column, row);
					found = true;
					break;
				}
			}
			if (!found) {
				enemy.setLocation(column, row);
				enemy.setMoveDirection(((enemy.getMoveDirection().getColumn() + 2) % 3) - 1, ((enemy).getMoveDirection().getRow() + 2) % 3 - 1);
				enemys.push_back(enemy);
				return true;
			}
			else
				return true;
		}
	}
	return false;
}
void Room::conflict(Enemy* enemy, int score) {
	printerMsg(info, "booom");
	//(*player).addScore(score);
	delay(1500);
	printerMsg(info, " ");
}

// automatic setup
void Room::moveEnemy(Enemy* enemy) {
	Point actLocation = (*enemy).getLocation();
	int i = 0;
	bool ok = false;
	while (i < 10 && !ok) { // i < 10 so the loop is not infinite
		// first in current direction, if impossible - change
		if (!(ok = moveEnemy((*enemy).getMoveDirection().getColumn(), (*enemy).getMoveDirection().getRow(), enemy))) {
			int s = (((*enemy).getMoveDirection().getColumn() + 2) % 3) - 1; // choosing new direction, where the enemy can move
			(*enemy).setMoveDirection(s, (((*enemy).getMoveDirection().getRow() + 2 + s) % 3) - 1);
		}
		i++;
	}
}

//manual setup
bool Room::moveEnemy(int columnStep, int rowStep, Enemy* enemy) {
	int actColumn = (*enemy).getLocation().getColumn();
	int actRow = (*enemy).getLocation().getRow();
	if ((0 == columnStep && 0 == rowStep) || !canEnemyMove(actColumn + columnStep, actRow + rowStep))
		return false;
	setInner(actColumn, actRow);
	// conflict 
	/*if ((*player).getLocation().getColumn() == actColumn + columnStep && (*player).getLocation().getRow() + rowStep == actRow) {
		conflict(enemy, -50);
		for (int i=0;i<enemys.size();i++)
			if ((*enemy).id=enemys[i].id)
		enemys.erase(enemys.begin()+i);
	}
	else
	setEnemy(actColumn + columnStep, actRow + rowStep, *enemy);*/

	return true;
}


// time between enemies moves
void Room::moveEnemys() {
	if (clock() / CLOCKS_PER_SEC - last_move_enemy_time < 0.3) // for enemies not to move to fast, every 0.3s
		return;
	last_move_enemy_time = clock() / CLOCKS_PER_SEC;
	int selectedEnemy = rand() % enemys.size(); // chooses only one enemy to move
	moveEnemy(&enemys[selectedEnemy]);
	delay(4);
	shotEnemys();
}


void Room::shotEnemys() {
	int selectedEnemy = rand() % enemys.size(); //choose one enemy to shot
	int actColumn = enemys[selectedEnemy].getLocation().getColumn();
	int actRow = enemys[selectedEnemy].getLocation().getRow();
	for (int i = 1; i < 4; i++) {
		actColumn = actColumn + enemys[selectedEnemy].getMoveDirection().getColumn(); // shoots in moving direction
		actRow = actRow + enemys[selectedEnemy].getMoveDirection().getRow();
		// if enemy can no longer move forward, escape
		if (!canEnemyMove(actColumn, actRow))
			return;
		RoomElement* actEl = get(actColumn, actRow);
		printer(actColumn, actRow, sign_shot);
		//affecting player
	/*	if ((*player).getLocation().getColumn() == actColumn && (*player).getLocation().getRow() == actRow) {
			conflict(&enemys[selectedEnemy], -10);
		}else
		delay(100);*/
		printer(actColumn, actRow, (*actEl).icon); // to remove shots from previous postition
	}
}


GameAction Room::motionSimulation(int column, int row, Creature* el) {
	RoomElement* actEl = get(column, row);
	setInner((*el).getLocation().getColumn(), (*el).getLocation().getRow());
	delay(100);
	if ((*actEl).id == (*p_room_door).id) {

		// imitating movement
		printer(column, row, (*el).icon);
		return exitRoom;
	}
	put(column, row, el);
	(*el).setLocation(column, row);
	return served;
}

bool Room::setDoor(int column, int row) {
	if ((column == 0 || column == width - 1 || row == 0 || row == height - 1)
		&& !(column == row)
		&& !(column == 0 && row == height - 1)
		&& !(column == width - 1 && row == 0)) {
		put(column, row, p_room_door);
		return true;
	}
	return false;
}

bool Room::isInner(int column, int row) {
	if (roomMap[row][column - 1].id == (*p_room_door).id
		|| roomMap[row][column].id == (*p_room_door).id
		|| roomMap[row][column + 1].id == (*p_room_door).id
		|| roomMap[row - 1][column].id == (*p_room_door).id)
		return false;
	if (roomMap[row - 1][column].id != (*p_room_inner).id && roomMap[row + 1][column].id != (*p_room_inner).id)
		return false;
	return true;

	/*bool Room::canPut(int column, int row) {
		return get(column, row).canPass;
	}*/
}

Point Room::getRandomInner()
{
	int i = 0;
	bool ok = false;
	int row, column;
	while (i < 40 && !ok) {
		row = (rand() % (height - 2)) + 1;
		column = (rand() % (width - 2)) + 1;
		ok = isInner(column, row);
		i++;
	}
	return Point(column, row);
}



