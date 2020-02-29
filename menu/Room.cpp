#include "Room.h"
#include "Screen.h"


Room::Room(int width, int height) {
	last_move_enemy_time = clock() / CLOCKS_PER_SEC;
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

bool Room::canPlayerMove(int column, int row) {
	return get(column, row).canPass;
}

bool Room::canEnemyMove(int column, int row) {
	RoomElement el = get(column, row);
	return el.canPass && el.id != room_door.id && el.id != room_treasure.id;
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
	return getEnemyById(get(column, row).getId());

}

Enemy* Room::getEnemyById(int id) {
	for (int i = 0; i < enemys.size(); ++i) {
		if (enemys[i].id == id)
			return &enemys[i];
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
				enemy.setMoveDirection(((enemy.getMoveDirection().getColumn() + 2) % 3) - 1, ((enemy).getMoveDirection().getRow() + 2) % 3 - 1);
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
	bool ok = false;
	while (i < 10 && !ok) { // i < 10 so the loop is not infinite
		// najpierw w poprzednim kierunku, a jak siê nieda to zmiana
		if (!(ok = moveEnemy((*enemy).getMoveDirection().getColumn(), (*enemy).getMoveDirection().getRow(), enemy))) {
			int s = (((*enemy).getMoveDirection().getColumn() + 2) % 3) - 1;
			(*enemy).setMoveDirection(s, (((*enemy).getMoveDirection().getRow() + 2+s) % 3) - 1);
		}
		i++;
	}
}

bool Room::moveEnemy(int columnStep, int rowStep, Enemy* enemy) {
	int actColumn = (*enemy).getLocation().getColumn();
	int actRow = (*enemy).getLocation().getRow();
	if ((0 == columnStep && 0 == rowStep) || !canEnemyMove(actColumn + columnStep, actRow + rowStep))
		return false;
	setInner(actColumn, actRow);
	setEnemy(actColumn + columnStep, actRow + rowStep, *enemy);
	return true;
}


// time between enemies moves
void Room::moveEnemys() {
	if (clock() / CLOCKS_PER_SEC - last_move_enemy_time < 0.3)
		return;
	last_move_enemy_time = clock() / CLOCKS_PER_SEC;
	int selectedEnemy = rand() % enemys.size();
	moveEnemy(&enemys[selectedEnemy]);
	shotEnemys();
}


void Room::shotEnemys() {
	int selectedEnemy = rand() % enemys.size();
	int actColumn = enemys[selectedEnemy].getLocation().getColumn();
	int actRow = enemys[selectedEnemy].getLocation().getRow();
	for (int i = 1; i < 3; i++) {
		delay(50);
		actColumn = actColumn + enemys[selectedEnemy].getMoveDirection().getColumn();
		actRow = actRow + enemys[selectedEnemy].getMoveDirection().getRow();
		if (!canEnemyMove(actColumn, actRow))
			return;
		RoomElement actEl = get(actColumn, actRow);
		printer(actColumn, actRow, '.');
		delay(250);
		printer(actColumn, actRow, actEl.icon);
	}
}


GameAction Room::movePlayer(int columnStep, int rowStep, Player* player) {
	int actColumn = (*player).getLocation().getColumn();
	int actRow = (*player).getLocation().getRow();
	RoomElement actEl = get(actColumn + columnStep, actRow + rowStep);
	setInner(actColumn, actRow);
	//delay(100);
	if (isDoor(actColumn + columnStep, actRow + rowStep)) {
		(*player).addScore(actEl.score);
		//udawanie ruchu
		printer(actColumn + columnStep, actRow + rowStep, (*player).icon);
		return exitRoom;
	}
	if (canPlayerMove(actColumn + columnStep, actRow + rowStep)) {
		(*player).addScore(actEl.score);
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
	if (canPlayerMove(column, row))
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



