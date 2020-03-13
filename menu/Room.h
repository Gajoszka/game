#pragma once
#include <xiosbase>
#include <vector>
#include "RoomElement.h"
#include "Enemy.h"
//#include "Player.h"
#include "GameDef.h"
#include "GameType.h"
#include <ctime>


using namespace std;

class Room {
public:
	Room(int width, int height);
	/*void addObserver(Observer* observer) {
		this->observers.push_back(observer);
	}*/
	void setPrinter(printElement printer) { //following the point on the screen
		this->printer = printer;
	}
	void setPrinterMessage(printMessage printer) { //displaying info in specified place
		this->printerMsg = printer;
	}
	bool put(int column, int row, RoomElement* el);
	RoomElement* get(int column, int row);
	bool setWall(int column, int row);
	bool setInner(int column, int row);
	bool setDoor(int column, int row);
	bool setEnemy(int column, int row, Enemy enemy);
	void shotEnemys();
	void moveEnemys();
	void moveEnemy(Enemy* enemy);
	bool moveEnemy(int columnStep, int rowStep, Enemy* enemy);
	/*bool setPlayer(int column, int row, Player* player);
	bool setPlayer(Player* player);*/
	bool setScale(int column, int row);
	bool setTreasure(int column, int row);
	bool isInner(int column, int row);
	bool canEnemyMove(int column, int row);
	bool isEnemy(int column, int row);
	Enemy* getEnemy(int column, int row);
	Enemy* getEnemyById(int id);
	Point getRandomInner();
	GameAction motionSimulation(int column, int row, Creature* el);
	int getScore(int column, int row) {
		return (*get(column, row)).score;
	}

	char getIcon(int column, int row) {
		return (*get(column, row)).icon;
	}

	int getId(int column, int row) {
		return (*get(column, row)).id;
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
	//GameAction movePlayer(int columnStep, int rowStep);
	~Room();
private:
	int width;
	int height;
	//Player* player;
	vector<vector<RoomElement>> roomMap; //2d vector

	void conflict(Enemy* enemy, int score);
	vector<Enemy> enemys;
	printElement printer = nullptr;
	printMessage printerMsg = nullptr;
	clock_t last_move_enemy_time;

	

	
};



