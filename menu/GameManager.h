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
	

protected:

private:
	bool inp = true;
	bool endGame = false;
	KeyFunctions move;
	Room room;
	Stats stats;
	InfoDisplay info;
	Player player;
	void playerGoTo(int x,int y);
};