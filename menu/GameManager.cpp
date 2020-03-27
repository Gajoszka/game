#include "GameManager.h"
#include "Screen.h"
#include <iostream>
#include <windows.h>
#include <stdio.h>
#include "GameDef.h"
#include "FloorBuilder.h"
/* Controls game flow */
using namespace std;

void GameManager::play(string playerName) {
	
	this->player = new Player(playerName);
	(*player).setPrinterMsg(std::bind(&GameLayout::print, layout, std::placeholders::_1, std::placeholders::_2));
	srand(time(NULL)); // make rand more randomise
	layout.printName((*player).getName());
	createFloor();
	keyReader();
}

// floor creation
void GameManager::createFloor()
{
	if (actFloor != nullptr)
		delete actFloor;
	FloorBuilder floorBuilder();
	
	actFloor = new Floor();
	actFloor->setPlayer(player);
	actFloor->setLayout(&layout);
	actFloor->createRoom();
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
					break;
				case KEY_F3:
					(*player).addScore(-10);
					layout.print(score,to_string((*player).getScore()));
					action = exitRoom;
					break;
				case KEY_F4:
					action = buy_ammunition;
					break;
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
	//action = (*getRoom()).runAction(action);
	action = actFloor->runAction(action);
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

// destructor
GameManager::~GameManager() {
	if (actFloor != nullptr)
		delete actFloor;
	delete player;
	layout.shutCursor(true);
}