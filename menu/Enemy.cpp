#include "Enemy.h"

void Enemy::setMoveDirection(int column, int row) {
	moveDirection.setColumn(column);
	if (0 == column == row)
		row = -1;
	moveDirection.setRow(row);
}