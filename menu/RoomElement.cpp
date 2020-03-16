#include "RoomBuilder.h"
#include "Player.h"
#include "Creature.h"

GameAction RoomElement::conflict(Creature* creature) {
	if (score != 0)
		if (Player* player = dynamic_cast<Player*>(creature))
			player->addScore(score);
	return canPass ? can_move : stop;
}