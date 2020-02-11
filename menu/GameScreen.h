#include <stdlib.h>
#ifndef GAMESCREEN_H
#define GAMESCREEN_H


class GameScreen
{
public:
	GameScreen();
	bool inp = true;
	int x = 10, y = 10;
	char player = '@';
	void clear();
	void movement();

protected:

private:
};

#endif // GAMESCREEN_H
