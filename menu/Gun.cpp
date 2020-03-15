#include "Gun.h"
#include "Player.h"

GameAction Gun::conflict(Player* player)
{
		RoomElement::conflict(player);
		magazine--;
		player->boom();
		return served;
}
