#include "RoomElementFactory.h"
/* Creating room elements */

RoomElementFactory::RoomElementFactory() {}

RoomElement* RoomElementFactory::get(int id)
{
	switch (id)
	{
	case id_door:
		return getDoor();
	case id_inner:
		return getInner();
	case id_wall:
		return getWall();
	case id_scale:
		return getScale();
	case id_treasure:
		return getTreasure();

	default:
		if (id >= id_enemy_min)
			return getEnemy(id);
		if (id > id_gun_min)
			return getGun();
		break;
	}
	return nullptr;
}

Gun* RoomElementFactory::getGun()
{
	{
		return new Gun();
	}
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

void RoomElementFactory::clearGuns()
{
	for (int i = 0; i < guns.size(); i++)
		delete guns[i];
	guns.clear();
}

// destructor
RoomElementFactory::~RoomElementFactory()
{
	delete inner;
	delete wall;
	delete scale;
	delete pTreasure;
	clearEnemys();
	clearGuns();
}