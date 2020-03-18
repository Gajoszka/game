#pragma once
using namespace std;

/* Child class inheriting from Creature class
*/
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
	
	Room* room;
	RoomElement* canMove(int column, int row);
	Gun* gun;
	Point changeDirection(Point direction);
};

