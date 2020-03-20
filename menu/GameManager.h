#pragma once
/* Controls game flow */
#include "Frame.h"
#include "Player.h"
#include "RoomFrame.h"
#include "GameDef.h"
#include "GameLayout.h"
#include "Floor.h"

class GameManager
{
public:
	GameManager() : layout() {};
	RoomFrame* getRoom() {
		return layout.getRoomFrame();
	}
	void play(string player);
	GameAction runAction(GameAction action);
	~GameManager();

protected:
	void createFloor();

private:
	void keyReader();
	GameLayout layout;
	Player *player=nullptr;
	Floor* actFloor;
};