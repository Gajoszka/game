#include "GameManager.h"
#include "Frame.h"
#include "Screen.h"
#include "KeyFunctions.h"
#include "Game.h"
#include "InfoDisplay.h"
#include "Room.h"
#include "Stats.h"
#include <iostream>

using namespace std;

void GameManager::play() {
	player.setX(1);
	player.setY(1);
	playerGoTo(rand()%40,rand()%15);
	while (!endGame) {
		Sleep(10000);
		move.movement();
		endGame = true;
	}
	
}

void GameManager::keyReader() {
	int x, y;
	while (inp) {
	
		char move = _getch(); // keyboard response
		switch (move) {
		case KEY_UP:
			playerGoTo(0,-1);
			break;
		case KEY_DOWN:
			playerGoTo(0, +1);
			break;
		case KEY_LEFT:
			playerGoTo(-1, 0);
			break;
		case KEY_RIGHT:
			playerGoTo(+1, 0);
			break;
		case KEY_END:
			inp = false;
		}
	}
};


void GameManager::playerGoTo(int x, int y) {
	int xAct = player.x + x;
	int yAct = player.y + y;
	if (room.isInside(xAct, yAct)) {
		player.setX(xAct);
		player.setY(yAct);
		room.printPoint(xAct, yAct, player.getP());
	}

