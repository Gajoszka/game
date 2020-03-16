#include "GameManager.h"
#include "Screen.h"
#include <iostream>
#include <windows.h>
#include <stdio.h>
#include "GameDef.h"
#include "RoomBuilder.h"

using namespace std;

// 
void GameManager::play(Player* player) {
	this->player = player;
	(*player).setPrinterMsg(std::bind(&GameLayout::print, layout, std::placeholders::_1, std::placeholders::_2));
	srand(time(NULL)); // make rand more randomise
	layout.printName((*player).getName());
	//createFloor();
	actFloor.setPlayer(player);
	actFloor.setLayout(&layout);
	actFloor.createRoom();
	keyReader();
}

void GameManager::createFloor()
{


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
				case KEY_F3:
					(*player).addScore(-10);
					layout.print(score,to_string((*player).getScore()));
					action = exitRoom;
					break;
				case KEY_F4:
					action = bay_ammunition;
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
			runAction(action);
		}
		else
			runAction(moveEnemy); // if nothing pressed - enemy move
	}
}

// escaping room and creating a new one


// manage occuring actions
void GameManager::runAction(GameAction action)
{
	//action = (*getRoom()).runAction(action);
	action = actFloor.runAction(action);
	switch (action)
	{
	case served:
		break;
	case Failed:
		break;
	default:
		break;
	}
}

GameManager::~GameManager() {
	layout.shutCursor(true);
}




