#include "RoomMap.h"

bool RoomMap::canPut( int row, int column) {
	if (roomMap[row][column - 1].id == room_door.id
		|| roomMap[row][column].id == room_wall.id
		|| roomMap[row][column + 1].id == room_door.id)
		return false;
	if (roomMap[row - 1][column].id != room_inner.id && roomMap[row + 1][column].id != room_inner.id)
		return false;
	return true;
}


