#pragma once
using namespace std;

/* Child class inheriting from Creature class
*/
#include "Creature.h"
#include "GameDef.h"
#include "Player.h"


class Enemy : public Creature
{
public:
	// enemy extends creature with its unique data
	Enemy(int id) : Creature(id+1000,sign_enemy, 2, 1, 1), moveDirection( 1,0){
		//this->room = room;
	};
	void setRoom(Room* room);
	void move();
	bool move(int columnStep, int rowStep);
	GameAction conflict(Player* player);
private:
	Point moveDirection;
	Room* room;
};

