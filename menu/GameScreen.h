#include <stdlib.h>
#include "Frame.h"
#include "Room.h"
#include "Stats.h"
#include "InfoDisplay.h"
#ifndef GAMESCREEN_H
#define GAMESCREEN_H


class GameScreen
{
public:
	GameScreen() : room(), stats(), info() {
		room.print(1,1);
		stats.print(46, 1);
		info.print(1,16);
	};
	void play();

protected:

private:
	bool endGame = false;
	Room room;
	Stats stats;
	InfoDisplay info;
};

#endif // GAMESCREEN_H
