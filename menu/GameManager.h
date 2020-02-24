#pragma once
#include <stdlib.h>
#include "Frame.h"
#include "Player.h"
#include "Room.h"
#include "Stats.h"
#include "InfoDisplay.h"
#include "MainFrame.h"
#include "GameAction.h"


#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_END 79
#define KEY_F5 63
#define KEY_F10 68

class GameManager
{
public:
	GameManager() : mainFrame(), statsFrame(), infoFrame(), player() {
		
	};
	Room* getRoom() {
		return mainFrame.getRoom();
	}
	void play();
	void keyReader();
	void shutCursor(bool visible);
	void exitFromRoom();
	void runAction(GameAction action);
	~GameManager();

protected:
	void createRoom();

private:
	MainFrame mainFrame;
	Stats statsFrame;
	InfoDisplay infoFrame;
	Player player;
};