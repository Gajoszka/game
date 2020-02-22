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
	shutCursor(false);
	player.setX(1);
	player.setY(1);
	while (!playerGoTo(rand()%45,rand()%18));
	while (!endGame) {
		keyReader();	
	}
	
}

void GameManager::keyReader() {

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
void GameManager::shutCursor(bool visible) {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ccur;
	ccur.dwSize = sizeof(CONSOLE_CURSOR_INFO);
	ccur.bVisible = visible;
	SetConsoleCursorInfo(hStdOut, &ccur);
}

bool GameManager::playerGoTo(int x, int y) {
	int xAct = player.x + x;
	int yAct = player.y + y;
	room.printPoint(player.x, player.y, ' ');
	Sleep(30);
	bool result = true;
	if (!room.isInside(xAct, yAct)) {
		 xAct = player.x ;
		 yAct = player.y;
		 result = false;
	}
	player.setX(xAct);
	player.setY(yAct);
	room.printPoint(xAct, yAct, player.getP());
	return result;
}

GameManager::~GameManager() {
	shutCursor(true);
}