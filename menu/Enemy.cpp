#include "Enemy.h"
#include "Player.h"

//void Enemy::conflict(Player* player)
//{
//	player->addScore(score);
//}

void Enemy::setMoveDirection(int column, int row) {
	moveDirection.setColumn(column);
	if (0 == column == row)
		row = -1;
	moveDirection.setRow(row);
}