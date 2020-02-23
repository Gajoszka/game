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
	RoomBuilder roomBuilder;
	roomBuilder.setWallCount(3);
	mainFrame.setRoom(roomBuilder.build());
	mainFrame.print(1, 1);
	stats.print(50, 1);
	info.print(1, 20);
	player.setLocation((*getRoom()).getTop().getX()+1,(*getRoom()).getTop().getY()+1);
	int i = 0;
	while (!playerGoTo(i, i))
		i++;
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
	int xAct = player.getLocation().getX() + x;
	int yAct = player.getLocation().getY() + y;
	player.clear();
	Sleep(30);
	bool result = true;
	if (!(*getRoom()).isInside(xAct, yAct)) {
		 xAct = player.getLocation().getX();
		 yAct = player.getLocation().getY();
		 result = false;
	}
	player.print(xAct, yAct);
	return result;
}

GameManager::~GameManager() {
	shutCursor(true);
}