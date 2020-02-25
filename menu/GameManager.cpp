#include "GameManager.h"
#include "Frame.h"
#include "Screen.h"
#include "InfoDisplay.h"
#include "Room.h"
#include "Stats.h"
#include <iostream>
#include <windows.h>
#include <stdio.h>
#include "RoomMapBuilder.h"

using namespace std;

void GameManager::play() {
	shutCursor(false);
	setFont();
	statsFrame.print(50, 1);
	infoFrame.print(1, 20);
	infoFrame.setContent(4, "F5-new room, F10-exit");
	createRoom();
	keyReader();
}

void GameManager::addScore(int score) {
	player.addScore(score);
	statsFrame.printScore(player.getScore());
}

void GameManager::keyReader() {
	GameAction action = served;
	char key;
	while (action != endGame) {
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
}

void GameManager::setFont() {
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof cfi;
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;
	cfi.dwFontSize.Y = 20;
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	wcscpy_s(cfi.FaceName, L"Lucida Console");
	wcscpy_s(cfi.FaceName, L"Consolas");
	//SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
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
	addScore(5);
	this->infoFrame.printTemporaryContent("zmiana pokoju");
	Sleep(1000);
	createRoom();
	this->infoFrame.printTemporaryContent("Nowy pokoj");
	Sleep(1000);
	this->infoFrame.printInside();
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
	shutCursor(true);
}

void GameManager::createRoom()
{
	RoomMapBuilder roomBuilder(45,15);
	roomBuilder.setObstacleCount(min((rand() % (max(player.getScore(), 6))) + 1, 10));
	roomBuilder.setDoorCount(1);
	roomBuilder.setTreasure(rand() % 10);
	(*getRoom()).setMap(roomBuilder.build());
	mainFrame.print(1, 1);
	(*getRoom()).setPlayer(&player);


}
