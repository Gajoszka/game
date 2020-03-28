#pragma once
/* Controls game flow */
#include "Frame.h"
#include "Player.h"
#include "RoomFrame.h"
#include "GameDef.h"
#include "GameLayout.h"
#include "Shop.h"
#include "Floor.h"

class GameManager
{
public:
	GameManager() : layout() {};
	RoomFrame* getRoom() {
		return layout.getRoomFrame();
	}
	void play(string player);
	GameAction shop();
	GameAction runAction(GameAction action);
	void timerStart();
	void timerStop();
	~GameManager();

protected:
	void createFloor();
	
private:
	printMessage printerMsg = nullptr;
	clock_t start, end;
	short seconds;
	short minutes;
	void keyReader();
	Shop shopping;
	GameLayout layout;
	Player* pPlayer=nullptr;
	Floor* pActFloor;
};