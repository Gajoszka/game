#pragma once
#include <stdlib.h>
#include "Frame.h"
#include "Player.h"
#include "Room.h"
#include "Stats.h"
#include "InfoDisplay.h"


#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_END 79

class GameManager
{
public:
	GameManager() : room(), stats(), info(), player() {
		room.print(1,1);
		stats.print(50, 1);
		info.print(1,20);
	};
	void play();
	void keyReader();
	void shutCursor(bool visible);
	~GameManager();

protected:

private:
	bool inp = true;
	bool endGame = false;
	Room room;
	Stats stats;
	InfoDisplay info;
	Player player;
	bool playerGoTo(int x,int y);
};