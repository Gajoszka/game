#include "GameManager.h"
#include "Screen.h"
#include <iostream>
#include <windows.h>
#include <stdio.h>
#include "RoomMapBuilder.h"

using namespace std;

// 
void GameManager::play(Player* player) {
	this->player = player;
	srand(time(NULL));
	layout.printName((*player).getName());
	createRoom();
	(*getRoom()).setPlayer(player);
	keyReader();
}

// score counter, adding score to current game
void GameManager::addScore(int score) {
	if (score == 0)
		return; // escaping if statement
	(*player).addScore(score);
	layout.printScore((*player).getScore());
}

// reading user input
void GameManager::keyReader() {
	GameAction action = served;
	char key;
	while (action != endGame) {
		if (_kbhit()) { // 
			key = _getch(); // receiving key input
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

// escaping room and creating a new one
void GameManager::exitFromRoom()
{
	addScore(5);
	this->layout.printInfo("room change");
	Sleep(1000);
	createRoom();
	this->layout.printInfo("  ");
	Sleep(1000);
	this->layout.printInfo("");
}

// manage occuring actions
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
	roomBuilder.setScaleCount((rand() % min(max(8,(*player).getScore()), 15)) + 1);
	roomBuilder.setEnemyCount((rand() % min(max(3,(*player).getScore()), 10)) + 1);
	roomBuilder.setDoorCount(1);
	roomBuilder.setTreasureCount(rand() % 12);
	layout.printRoom(roomBuilder.build());
}
