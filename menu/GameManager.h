#pragma once
#include <stdlib.h>
#include "Frame.h"
#include "Player.h"
#include "RoomFrame.h"

#include "GameAction.h"
#include "GameLayout.h"


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
	GameManager() : layout() {
		
	};
	RoomFrame* getRoom() {
		return layout.getRoom();
	}
	void play(Player *player);
	void exitFromRoom();
	void runAction(GameAction action);
	~GameManager();

protected:
	void createRoom();

private:
	
	void keyReader();
	void addScore(int s);
	GameLayout layout;
	Player *player=nullptr;
};