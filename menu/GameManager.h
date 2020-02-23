#pragma once
#include <stdlib.h>
#include "Frame.h"
#include "Player.h"
#include "Room.h"
#include "Stats.h"
#include "InfoDisplay.h"
#include "MainFrame.h"


#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_END 79

class GameManager
{
public:
	GameManager() : mainFrame(), stats(), info(), player() {
		
	};
	Room* getRoom() {
		return mainFrame.getRoom();
	}
	void play();
	void keyReader();
	void shutCursor(bool visible);
	~GameManager();

protected:

private:
	bool inp = true;
	bool endGame = false;
	MainFrame mainFrame;
	Stats stats;
	InfoDisplay info;
	Player player;
	bool playerGoTo(int x,int y);
};