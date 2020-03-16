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
	Enemy(int id) : Creature(id+1000,sign_enemy, 2, 1, 1){
		score = -15;
	};
	void setRoom(Room* room);
	void move();
	bool move(int columnStep, int rowStep);
	void shot();
	GameAction conflict(Creature* creature);
	void death();
	~Enemy();
private:
	
	Room* room;
	RoomElement* canMove(int column, int row);
	Gun* gun;
	Point changeDirection(Point direction);
};

