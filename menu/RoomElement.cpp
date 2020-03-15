#include "RoomBuilder.h"
#include "Player.h"

GameAction RoomElement::conflict(Player* player) {
	(*player).addScore(score);
	return canPass ? can_move : stop;
}