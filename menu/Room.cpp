#include "Room.h"
#include "Screen.h"
#include "Enemy.h"
#include "RoomElementFactory.h"


Room::Room(int width, int height, RoomElementFactory* elementFactory) {
	last_move_enemy_time = clock() / CLOCKS_PER_SEC;
	this->width = width;
	this->height = height;
	this->elementFactory = elementFactory;
	for (int row = 0; row < height; row++) {
		vector<RoomElement*> tmp;
		for (int i = 0; i < width; i++) {
			tmp.push_back((*elementFactory).getInner());
		}
		roomMap.push_back(move(tmp));
	}
}

RoomElement* Room::get(int column, int row) {
	if (row >= 0 && row < height && column >= 0 && column < width) {
		return roomMap[row][column];
	}
	return nullptr;
}
//
//bool Room::setEnemy(int column, int row, Enemy* enemy) {
//	if (isInner(column, row)) {
//		if (put(column, row, enemy)) {
//			(*enemy).setRoom(this);
//			bool found = false;
//			for (int i = 0; i < enemys.size(); i++) {
//				if ((*enemys[i]).id == (*enemy).id) {
//					(*enemys[i]).setLocation(column, row);
//					found = true;
//					break;
//				}
//			}
//			if (!found) {
//				(*enemy).setLocation(column, row);
//				(*enemy).setMoveDirection((((*enemy).getMoveDirection().getColumn() + 2) % 3) - 1, (((*enemy)).getMoveDirection().getRow() + 2) % 3 - 1);
//				enemys.push_back(enemy);
//				return true;
//			}
//			else
//				return true;
//		}
//	}
//	return false;
//}


Room::~Room()
{
	for (vector<RoomElement*> vector : roomMap) {
		vector.clear();
	}
	roomMap.clear();
}

bool  Room::put(int column, int row, RoomElement* el) {
	if (row >= 0 && row < height && column >= 0 && column < width) {
		roomMap[row][column] = el;
		if (printer != nullptr)
			printer(column, row, (*el).icon);
		if (Creature* t = dynamic_cast<Creature*>(el))
			(*(Creature*)el).setLocation(column, row);
		return true;
	}
	return false;
}

bool  Room::putInInner(RoomElement* el) {
	Point point = getRandomInner();
	return put(point.getColumn(), point.getRow(), el);
}

bool Room::isEnemy(int column, int row) {
	return (*get(column, row)).id > 10000;
}

// time between enemies moves
void Room::moveEnemys() {
	if (clock() / CLOCKS_PER_SEC - last_move_enemy_time < 0.24) // for enemies not to move to fast, every 0.3s
		return;
	last_move_enemy_time = clock() / CLOCKS_PER_SEC;
	// chooses only one enemy to move
	(*(*elementFactory).getRandEnemy()).move();
	(*(*elementFactory).getRandEnemy()).move();
	//shotEnemys();
}


void Room::shotEnemys() {
	Enemy* enemy = (*elementFactory).getRandEnemy(); //choose one enemy to shot
	int actColumn = (*enemy).getLocation().getColumn();
	int actRow = (*enemy).getLocation().getRow();
	//for (int i = 1; i < 4; i++) {
	//	actColumn = actColumn + (*enemys[selectedEnemy]).getMoveDirection().getColumn(); // shoots in moving direction
	//	actRow = actRow + (*enemys[selectedEnemy]).getMoveDirection().getRow();
	//	// if enemy can no longer move forward, escape
	//	if (!canEnemyMove(actColumn, actRow))
	//		return;
	//	RoomElement* actEl = get(actColumn, actRow);
	//	printer(actColumn, actRow, sign_shot);
		//affecting player
	/*	if ((*player).getLocation().getColumn() == actColumn && (*player).getLocation().getRow() == actRow) {
			conflict(&enemys[selectedEnemy], -10);
		}else
		delay(100);*/
		//	printer(actColumn, actRow, (*actEl).icon); // to remove shots from previous postition
		//}
}


GameAction Room::moveCreature(int column, int row, int _delay, Creature* el) {
	RoomElement* actEl = get(column, row);
	put((*el).getLocation().getColumn(), (*el).getLocation().getRow(), (*elementFactory).getInner());
	delay(_delay);
	put(column, row, el);
	return served;
}


bool Room::isInner(int column, int row) {
	if ( column<1 || row<1 
		|| (*roomMap[row][column - 1]).id == id_door
		|| (*roomMap[row][column]).id == id_door
		|| (*roomMap[row][column + 1]).id == id_door
		|| (*roomMap[row - 1][column]).id == id_door)
		return false;
	if ((*roomMap[row - 1][column]).id != id_inner && (*roomMap[row + 1][column]).id != id_inner)
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

GameAction Room::runAction(GameAction action)
{
	moveEnemys();
	return action;
}



