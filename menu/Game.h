#pragma once
#include "GameManager.h"
#include"MainMenu.h"
class Game
{
public:
	Game() : menu() {};
	void start();
private:
	MainMenu menu;
};

