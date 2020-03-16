#include "RoomElementFactory.h"

RoomElementFactory::RoomElementFactory()
{
}

Enemy* RoomElementFactory::getEnemyById(int id)
{
	for (int i = 0; i < enemys.size(); i++)
		if (enemys[i]->id == id)
			return enemys[i];
	return nullptr;
}

void RoomElementFactory::removeEnemy(Enemy* enemy)
{
	auto it = std::find(enemys.begin(), enemys.end(), enemy);
	enemys.erase(it);
	delete enemy;
}

void RoomElementFactory::clearEnemys()
{
	for (int i = 0; i < enemys.size(); i++)
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
