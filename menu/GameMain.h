#ifndef GAMEMAIN_H
#define GAMEMAIN_H
#include "Player.h"
class GameMain
{
public:
	void GameIntro();


protected:

private:
	Player player;
	void movement();
	bool inp = true;
};

#endif // GAMEMAIN_H
