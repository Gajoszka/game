#pragma once
using namespace std;
/* Child class inheriting from Creature class, defining enemy creature*/
#include "Creature.h"
#include "GameDef.h"
#include "Player.h"
#include "Gun.h"


class Enemy : public Creature
{
public:
	// enemy extends creature with its unique data
	Enemy(int id) : Creature(id,sign_enemy, 2, 1, 1){
		score = -10;
	};
	void setRoom(Room* room);
	GameAction move();
	GameAction move(int columnStep, int rowStep);
	GameAction shot();
	GameAction conflict(Creature* creature);
	void death();
	~Enemy();
private:
	
	Room* pRoom;
	RoomElement* canMove(int column, int row);
	Gun* pGun;
	Point changeDirection(Point direction);
};

