#include <stdlib.h>
#ifndef GAMESCREEN_H
#define GAMESCREEN_H


class GameScreen
{
public:
	GameScreen();
	int x = 10, y = 10;
	char player = '@';
	void clear();

protected:

private:
};

#endif // GAMESCREEN_H
