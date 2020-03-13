#pragma once
using namespace std;

/* Child class inheriting from Creature class
*/
#include "Creature.h"
#include "GameDef.h"
//#include "Player.h"

class Player;

class Enemy : public Creature
{
public:
	// enemy extends creature with its unique data
	Enemy(int id) : Creature(id+1000,sign_enemy, 2, 1, 1), moveDirection( 1,0){
		//this->room = room;
	};
	//virtual void conflict(Player *player);
	void setMoveDirection(int column, int row);

	Point getMoveDirection() {
		return moveDirection;
	}
private:
	Point moveDirection;
};

