#include "Room.h"
#include "Screen.h"

Room::Room(int width, int height) {
	last_move_enemy_time = clock(); // CLOCKS_PER_SEC;
	this->width = width;
	this->height = height;;
	for (int row = 0; row < height; row++) {
		vector<RoomElement> tmp;
		for (int i = 0; i < width; i++) {
			tmp.push_back(room_inner);
		}
		roomMap.push_back(move(tmp));
	}
}

RoomElement Room::get(int column, int row) {
	if (row >= 0 && row < height && column >= 0 && column < width) {
		return roomMap[row][column];
	}
	return failed;
}
bool Room::setWall(int column, int row) {
	return set(column, row, room_wall);
}

bool Room::setScale(int column, int row) {
	if (canPut(column, row))
		return set(column, row, room_scale);
	return false;
}

bool Room::setTreacure(int column, int row) {
	if (canPut(column, row))
		return set(column, row, room_treasure);
	return false;
}

bool Room::canMove(int column, int row) {
	return get(column, row).canPass;
}

bool Room::isDoor(int column, int row) {
	return get(column, row).id == room_door.id;
}
bool Room::isEnemy(int column, int row) {
	return get(column, row).id > 10000;
}

bool Room::setInner(int column, int row) {
	if (get(column, row).id == room_door.id)
		return true;
	return set(column, row, room_inner);
}

Room::~Room()
{
	enemys.clear();
	for (vector<RoomElement> v : roomMap) {
		v.clear();
	}
	roomMap.clear();
}

bool  Room::set(int column, int row, RoomElement el) {
	if (row >= 0 && row < height && column >= 0 && column < width) {
		roomMap[row][column] = el;
		if (printer != nullptr)
			printer(column, row, el.icon);
		return true;
	}
	return false;
}
Enemy* Room::getEnemy(int column, int row) {
	return getEnemy(get(column, row).getId());

}

Enemy* Room::getEnemy(int id) {
	for (Enemy enemy : enemys) {
		if (enemy.id == id)
			return &enemy;
	}
	return NULL;
}


bool Room::setEnemy(int column, int row, Enemy enemy) {
	if (canPut(column, row)) {
		if (set(column, row, enemy)) {
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
				enemy.id = enemy.id + 10000;
				enemys.push_back(enemy);
				return true;
			}
			else
				return true;
		}
	}
	return false;
}

void Room::moveEnemy(Enemy* enemy) {
	Point actLocation = (*enemy).getLocation();
	int i = 0;
	int s;
	bool ok = false;
	while (i < 10 && !ok) { // i < 10 so the loop is not infinite
		// najpierw w poprzednim kierunku, a jak siê nieda to zmiana
		if (!(ok = moveEnemy((*enemy).getMoveDirection().getColumn(), (*enemy).getMoveDirection().getRow(), enemy))) {
			s=(((*enemy).getMoveDirection().getColumn()+2) % 3) - 1;
			(*enemy).setMoveDirection(s,((s+2)%3)-1);
		}
		i++;
	}

}

bool Room::moveEnemy(int columnStep, int rowStep, Enemy* enemy) {
	int actColumn = (*enemy).getLocation().getColumn();
	int actRow = (*enemy).getLocation().getRow();
	if (!canMove(actColumn + columnStep, actRow + rowStep))
		return false;
	setInner(actColumn, actRow);
	delay(12);
	setEnemy(actColumn + columnStep, actRow + rowStep, *enemy);
	return true;
}


// time between enemies moves
void Room::moveEnemys() {
	time_t current_time = time(NULL);
	if (clock() / CLOCKS_PER_SEC - last_move_enemy_time < 0.5)
		return;
	last_move_enemy_time = clock() / CLOCKS_PER_SEC;
	for (int i = 0; i < getEnemyCount(); ++i) {
		moveEnemy(getEnemy(i));
		delay(5);
	}
}


GameAction Room::movePlayer(int columnStep, int rowStep, Player* player) {
	int actColumn = (*player).getLocation().getColumn();
	int actRow = (*player).getLocation().getRow();
	setInner(actColumn, actRow);
	delay(12);
	if (isDoor(actColumn + columnStep, actRow + rowStep)) {
		//udawanie ruchu
		printer(actColumn + columnStep, actRow + rowStep, (*player).icon);
		return exitRoom;
	}
	if (canMove(actColumn + columnStep, actRow + rowStep)) {
		setPlayer(actColumn + columnStep, actRow + rowStep, player);
	}
	else
		setPlayer(actColumn, actRow, player);
	return served;
}


bool Room::setPlayer(Player* player) {

	while (!setPlayer(rand() % width, rand() % height, player));
	return true;
}


bool Room::setPlayer(int column, int row, Player* player) {
	if (canMove(column, row))
		if (set(column, row, *player)) {
			(*player).setLocation(column, row);
			return true;
		}
	return false;
}

bool Room::setDoor(int column, int row) {
	if ((column == 0 || column == width - 1 || row == 0 || row == height - 1)
		&& !(column == row)
		&& !(column == 0 && row == height - 1)
		&& !(column == width - 1 && row == 0)) {
		set(column, row, room_door);
		return true;
	}
	return false;
}

bool Room::canPut(int column, int row) {
	if (roomMap[row][column - 1].id == room_door.id
		|| roomMap[row][column].id == room_wall.id
		|| roomMap[row][column + 1].id == room_door.id
		|| roomMap[row - 1][column].id == room_door.id)
		return false;
	if (roomMap[row - 1][column].id != room_inner.id && roomMap[row + 1][column].id != room_inner.id)
		return false;
	return true;
}
//
//void RoomMap::notify(RoomElement* roomelement)
//{
//	for (int i = 0; i < observers.size(); i++) {
//		observers[i].
//	}
//}


