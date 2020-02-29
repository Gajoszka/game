#pragma once
#include <xiosbase>
#include <vector>
#include "RoomElement.h"
#include "Enemy.h"
#include "Player.h"
#include "GameDef.h"
#include <ctime>

const RoomElement room_wall = RoomElement(1, static_cast<char>(219), false, 0);
const RoomElement room_door = RoomElement(-1, ' ', true, 5);
const RoomElement room_scale = RoomElement(2, static_cast<char>(178), false, 0);
const RoomElement room_treasure = RoomElement(3, static_cast<char>(158), true, 2);
const RoomElement room_inner = RoomElement(0, ' ', true, 0);
const RoomElement room_enemy = RoomElement(4, static_cast<char>(172), false, 10);
const RoomElement failed = RoomElement(-11, ' ', false, 0);

using namespace std;

class Room {
public:
	Room(int width, int height);
	/*void addObserver(Observer* observer) {
		this->observers.push_back(observer);
	}*/
	void setPrinter(printElement printer) {
		this->printer = printer;
	}
	void setPrinterMessage(printMessage printer) {
		this->printerMsg = printer;
	}
	bool set(int column, int row, RoomElement el);
	RoomElement get(int column, int row);
	bool setWall(int column, int row);
	bool setInner(int column, int row);
	bool setDoor(int column, int row);
	bool setEnemy(int column, int row, Enemy enemy);
	void shotEnemys();
	void moveEnemys();
	void moveEnemy(Enemy* enemy);
	bool moveEnemy(int columnStep, int rowStep, Enemy* enemy);
	bool setPlayer(int column, int row, Player* player);
	bool setPlayer(Player* player);
	bool setScale(int column, int row);
	bool setTreacure(int column, int row);
	bool canPlayerMove(int column, int row);
	bool canEnemyMove(int column, int row);
	bool isDoor(int column, int row);
	bool isEnemy(int column, int row);
	Enemy* getEnemy(int column, int row);
	Enemy* getEnemyById(int id);

	int getScore(int column, int row) {
		return get(column, row).score;
	}

	char getIcon(int column, int row) {
		return get(column, row).icon;
	}

	int getWidth() {
		return width;
	}

	int getHeight() {
		return height;
	}

	vector<Enemy>* getEnemys() {
		return &enemys;
	}

	size_t getEnemyCount() {
		return enemys.size();
	}
	GameAction movePlayer(int columnStep, int rowStep, Player* player);
	~Room();
private:
	int width;
	int height;
	vector<vector<RoomElement>> roomMap;
	bool canPut(int row, int column);
	vector<Enemy> enemys;
	printElement printer = nullptr;
	printMessage printerMsg = nullptr;
	clock_t last_move_enemy_time;
};



