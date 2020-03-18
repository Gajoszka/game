#include "Gun.h"
#include "Player.h"
#include "Enemy.h"
#include "Screen.h"

GameAction Gun::conflict(Creature* creature)
{
	if (Enemy* enemy = dynamic_cast<Enemy*>(creature)) {
		enemy->death();
	}
	else if (Player* player = dynamic_cast<Player*>(creature)) {
		ammunition--;
		return player->decreseLives();
	}
	return served;
}

GameAction Gun::shot(Room* room, Creature* shooter) {
	if (!canShot())
		return served;
	Point shotDirection = shooter->lastMoveDirection;
	if (Enemy* enemy = dynamic_cast<Enemy*>(shooter)) {
		//random shoting direction
		int s = (rand() + 2) % 3 - 1; // choosing new direction, where the enemy can move
		shotDirection.setColumn(s);
		shotDirection.setRow(((shotDirection.getRow() + 2 + s) % 3) - 1);

	}
	if (0 == shotDirection.getColumn() && 0 == shotDirection.getRow())
		shotDirection.setColumn(-1);
	int nextColumn = shooter->getLocation().getColumn();
	int nextRow = shooter->getLocation().getRow();
	RoomElement* nextEl;
	--ammunition;
	for (int i = 1; i < range; i++) {
		nextColumn = nextColumn + shotDirection.getColumn(); // shoots in moving direction
		nextRow = nextRow + shotDirection.getRow();
		nextEl = room->get(nextColumn, nextRow);
		// if enemy can no longer move forward, escape
		if (nextEl==nullptr || !nextEl->canPass || nextEl->id==id_door)
			return served;
		room->printer(nextColumn, nextRow, icon);
		
		if (Enemy* enemy = dynamic_cast<Enemy*>(nextEl)) {
			if (Player* player = dynamic_cast<Player*>(shooter))
				player->addScore(abs(enemy->score));
			enemy->death();
			return served;
		}
		else if (Creature* creature = dynamic_cast<Creature*>(nextEl))
			return conflict(creature);
		delay(50);
		room->printer(nextColumn, nextRow, nextEl->icon); // to remove shots from previous postition
	}
	return served;
}
