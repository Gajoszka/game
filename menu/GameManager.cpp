#include "GameManager.h"
#include "Screen.h"
#include <ctime>
#include <iostream>
#include <windows.h>
#include <stdio.h>
#include "GameDef.h"
#include "FloorBuilder.h"
/* Controls game flow */
using namespace std;

void GameManager::play(string playerName) {
	
	layout.printLayout();
	this->pPlayer = new Player(playerName);
	(*pPlayer).setPrinterMsg(std::bind(&GameLayout::print, &layout, std::placeholders::_1, std::placeholders::_2));
	srand(time(NULL)); // make rand more randomise
	layout.printName((*pPlayer).getName());
	createFloor();
	keyReader();
}

GameAction GameManager::shop()
{
	system("CLS");
	shopping.openShop();
	_getch();
	layout.refresh();
	return served;
}

// floor creation
void GameManager::createFloor()
{
	if (pActFloor != nullptr)
		delete pActFloor;
	FloorBuilder floorBuilder();
	
	pActFloor = new Floor();
	pActFloor->setPlayer(pPlayer);
	pActFloor->setLayout(&layout);
	pActFloor->createRoom();
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
				case KEY_F1:
					action = shop();
				case KEY_F10:
					action = endGame;
					break;
				case KEY_F3:
					(*pPlayer).addScore(-10);
					layout.print(score,to_string((*pPlayer).getScore()));
					action = exitRoom;
					break;
				/*case KEY_F4:
					action = buy_ammunition;
					break;*/
				default:
					action = served;
				}
			}
			else {
				switch (key) {
				case KEY_SPACE:
					action = fire;
					break;
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
			action=runAction(action);
		}
		else
			action=runAction(moveEnemy); // if nothing pressed - enemy move
	}
	system("CLS");
}


// manage occuring actions
GameAction GameManager::runAction(GameAction action)
{
	action = pActFloor->runAction(action);
	switch (action)
	{
	case served:
		break;
	case Failed:
		break;
	case player_death:
		layout.print(info_delay, "END GAME");
		action = endGame;
	default:
		break;
	}
	return action;
}

void GameManager::timerStart() {
	/*start = clock();
	printerMsg(messageType::timer, to_string(start));*/
}

void GameManager::timerStop() {
	
}

// destructor
GameManager::~GameManager() {
	if (pActFloor != nullptr)
		delete pActFloor;
	delete pPlayer;
	layout.shutCursor(true);
}