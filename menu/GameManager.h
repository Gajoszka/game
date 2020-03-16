#pragma once
/* Controls game flow */
#include "Frame.h"
#include "Player.h"
#include "RoomFrame.h"
#include "GameDef.h"
#include "GameLayout.h"
#include "Floor.h"

// defining special keys
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_END 79
#define KEY_SPACE 32
#define KEY_F3 61
#define KEY_F4 62
#define KEY_F10 68

class GameManager
{
public:
	GameManager() : layout(){
		
	};
	RoomFrame* getRoom() {
		return layout.getRoomFrame();
	}
	void play(Player *player);
	void runAction(GameAction action);
	~GameManager();

protected:
	void createFloor();

private:
	void keyReader();
	GameLayout layout;
	Player *player=nullptr;
	Floor actFloor;
};