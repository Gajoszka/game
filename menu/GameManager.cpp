#include "GameManager.h"
#include "Screen.h"
#include "Room.h"
#include <iostream>
#include <windows.h>
#include <stdio.h>
#include "RoomMapBuilder.h"

using namespace std;

void GameManager::play(Player* player) {
	this->player = player;
	srand(time(NULL));
	layout.printName((*player).getName());
	createRoom();
	(*getRoom()).setPlayer(player);
	keyReader();
}

void GameManager::addScore(int score) {
	if (score == 0)
		return;
	(*player).addScore(score);
	layout.printScore((*player).getScore());
}

void GameManager::keyReader() {
	GameAction action = served;
	char key;
	while (action != endGame) {
		if (_kbhit()) {
			key = _getch();
			if (key == 0) {
				key = _getch();
				switch (key) {
				case KEY_F10:
					action = endGame;
					system("CLS");
					break;
				case KEY_F5:
					addScore(-10);
					action = exitRoom;
					break;
				default:
					action = served;
				}
			}
			else {
				switch (key) {
				case KEY_UP:
					action = key_up;
					break;
				case KEY_DOWN:
					action = key_down;
					break;
				case KEY_LEFT:
					action = key_left;
					break;
				case KEY_RIGHT:
					action = key_right;
					break;
				default:
					action = served;
				}
			}
			runAction(action);
		}
		else
			runAction(moveEnemy);
	}
}

void GameManager::exitFromRoom()
{
	addScore(5);
	this->layout.printInfo("zmiana pokoju");
	Sleep(1000);
	createRoom();
	this->layout.printInfo("Nowy pokoj");
	Sleep(1000);
	this->layout.printInfo("");
}

void GameManager::runAction(GameAction action)
{
	action = (*getRoom()).runAction(action);
	switch (action)
	{
	case served:
		addScore(0);
		break;
	case exitRoom:
		exitFromRoom();
		break;
	case Failed:
		break;
	default:
		break;
	}
}


GameManager::~GameManager() {

}

void GameManager::createRoom()
{
	RoomMapBuilder roomBuilder(45, 15);
	roomBuilder.setObstacleCount((rand() % min((*player).getScore()+4, 12)) + 1);
	roomBuilder.setEnemyCount((rand() % min((*player).getScore()+2, 10)) + 1);
	roomBuilder.setDoorCount(1);
	roomBuilder.setTreasureCount(rand() % 12);
	layout.printRoom(roomBuilder.build());
}
