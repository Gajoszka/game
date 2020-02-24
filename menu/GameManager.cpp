#include "GameManager.h"
#include "Frame.h"
#include "Screen.h"
#include "KeyFunctions.h"
#include "Game.h"
#include "InfoDisplay.h"
#include "Room.h"
#include "Stats.h"
#include <iostream>
#include "RoomMapBuilder.h"

using namespace std;

void GameManager::play() {
	shutCursor(false);
	statsFrame.print(50, 1);
	infoFrame.print(1, 20);
	infoFrame.setContent(4, "F5-new room, F10-exit");
	createRoom();
	keyReader();

}


void GameManager::keyReader() {
	GameAction action= served;
	while (action!=endGame) {
		
		char key = _getch(); // keyboard response
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
		case KEY_F10:
			action = endGame;
			system("CLS");
			break;
		case KEY_F5:
			statsFrame.addScore(-10);
			action = exitRoom;
			break;
		default:
			action = served;
		}
		runAction(action);

	}
}

void GameManager::shutCursor(bool visible) {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ccur;
	ccur.dwSize = sizeof(CONSOLE_CURSOR_INFO);
	ccur.bVisible = visible;
	SetConsoleCursorInfo(hStdOut, &ccur);
}

void GameManager::exitFromRoom()
{
	statsFrame.addScore(5);
	this->infoFrame.printTemporaryContent("zmiana pokoju");
	Sleep(1000);
	createRoom();
	this->infoFrame.printTemporaryContent("Nowy pokoj");
	Sleep(1000);
	this->infoFrame.printInside();
}

void GameManager::runAction(GameAction action)
{
	action= getRoom()->runAction(action);
	switch (action)
	{
	case served:
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
	shutCursor(true);
}

void GameManager::createRoom()
{
		RoomMapBuilder roomBuilder;
		roomBuilder.setObstacleCount(min((rand() % (max(statsFrame.getScore(),6)))+1,10));
		roomBuilder.setDoorCount(1);
		int map[15][45];
		roomBuilder.build(map);
		(*getRoom()).setMap(map);
		mainFrame.print(1, 1);
		(*getRoom()).setPlayer(&player);
	
		
}
