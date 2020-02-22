#include "GameScreen.h"
#include "Frame.h"
#include "Screen.h"
#include "KeyFunctions.h"
#include "Game.h"
#include "InfoDisplay.h"
#include "Room.h"
#include "Stats.h"
#include <iostream>

using namespace std;

void GameScreen::play() {
	while (!endGame) {
		Sleep(10000);
		endGame = true;
	}
}