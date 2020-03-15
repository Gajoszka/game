#include "RoomElementFactory.h"

RoomElementFactory::RoomElementFactory()
{
}

void RoomElementFactory::clearEnemys()
{
	for (int i=0;i< enemys.size();i++)
		delete enemys[i];
	enemys.clear();
}

RoomElementFactory::~RoomElementFactory()
{
	delete inner;
	delete wall;
	delete scale;
	delete treasure;
	clearEnemys();
	
}
