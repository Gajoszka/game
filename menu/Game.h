#pragma once
#include "GameScreen.h"
#include"MainMenu.h"
class Game
{
public:
	Game() : menu() {};
	void start();
private:
	MainMenu menu;
};

